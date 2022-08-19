#include <bits/stdc++.h>
#define int long long
const int Maxn = 50010;
struct Node
{
    int d, p;
}t[Maxn];
void debug(int *f, int len)
{
    for (int i = 0; i <= len; i++)
        std::cout << f[i] << " ";
    std::cout << "\n";
}
int n, C, st, dist;
int res[Maxn];
std::stack<int> q;
int calc(int x, int y) {return std::abs(t[x].d - t[y].d);}
bool check()
{
    for (int i = 1; i <= n; i++)
        if (calc(i, i + 1) > C) return true;
    if (st < t[1].d) return true;
    return false;
}

int find(int x)
{
    int Min = LONG_LONG_MAX, loc = 0;
    int sav = (x == 0) ? st : C;
    for (int i = x + 1; i <= n + 1; i++)
    {
        if (calc(x, i) > sav) break;
        if (t[i].p < Min)
            Min = t[i].p, loc = i;
    }
    return loc;
}
signed main()
{
    freopen("in", "r", stdin);
    scanf("%lld %lld %lld %lld", &n, &C, &st, &dist);
    t[n + 1].d = dist;
    for (int i = 1; i <= n; i++)
        scanf("%lld %lld", &t[i].d, &t[i].p);
    std::sort(t + 1, t + n + 2, [&](const Node &a, const Node &b){return a.d < b.d;});
    if (check())
        return puts("-1"), 0;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && t[q.top()].p > t[i].p)
            res[q.top()] = i, q.pop();
        q.push(i);
    }
    long long ans = 0;
    int cur = 0, fuel = st;
    t[0].p = 0;
    while (cur < n + 1)
    {
        // std::cout << t[cur].d;
        int pos = res[cur], cosume = calc(cur, pos);
        if (C >= cosume && pos != 0)
        {
            ans += (cosume - fuel) * t[cur].p;
            // std::cout << "-1->" << t[pos].d << " fuel=" << fuel << " " << (cosume - fuel) * t[cur].p << "\n";
            fuel = 0;
            cur = pos;
        }
        else
        {
            pos = find(cur);
            if (pos >= n + 1 && C >= calc(cur, pos))
                return printf("%lld\n", ans + (calc(cur, pos) - fuel) * t[cur].p), 0;
            // std::cout << "-2->" << t[pos].d << " fuel=" << fuel << " " << (C - fuel) * t[cur].p << "\n";
            ans += (C - fuel) * t[cur].p;
            fuel = (cur != 0) ? (C - calc(cur, pos)) : (st - calc(cur, pos));
            cur = pos;
        }
    }
    printf("%lld\n", ans);
    return 0;
}