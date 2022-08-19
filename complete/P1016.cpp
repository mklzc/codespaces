#include <bits/stdc++.h>
const int Maxn = 15;
int n;
double Dist, cosume, P, C, d[Maxn], p[Maxn];
double ans = 1e7;
double dis(int x, int y) {return std::fabs(d[x] - d[y]);}
double calc(int x, int y) {return dis(x, y) / cosume;}
void dfs(int pos, double cost, double rem)
{
    if (cost > ans) return;
    if (calc(pos, n + 1) < C)
        ans = std::min(ans, cost + (calc(pos, n + 1) - rem) * p[pos]);
    if (pos == n + 1)
        return void(ans = std::min(ans, cost));
    if (rem < calc(pos, pos + 1))
        dfs(pos + 1, cost + (calc(pos, pos + 1) - rem) * p[pos], 0);
    else
        dfs(pos + 1, cost, rem - calc(pos, pos + 1));
    dfs(pos + 1, cost + (C -  rem) * p[pos], (C - calc(pos, pos + 1)));
    for (int i = pos + 1; i <= n; i++)
    {
        if (p[i] >= p[pos]) continue;
        if (rem + calc(i, pos) <= C)
            dfs(pos + 1, cost + calc(i, pos) * p[pos], rem + calc(i, pos) - calc(pos, pos + 1));
    }
}
bool check()
{
    for (int i = 1; i <= n; i++)
        if (calc(i, i - 1) > C) return true;
    if (Dist - d[n] > C * cosume) return true;
    return false;
}
int main()
{
    scanf("%lf %lf %lf %lf %d", &Dist, &C, &cosume, &P, &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &d[i], &p[i]);
    if (check())
        return puts("No Solution"), 0;
    d[n + 1] = Dist, p[n + 1] = 0;
    // printf("%.2lf %.2lf %.2lf %.2lf\n", calc(1, 0), calc(2, 1), calc(3, 2), calc(4, 3));
    p[0] = P;
    dfs(0, 0, 0);
    printf("%.2lf\n", ans);
    return 0;
}
