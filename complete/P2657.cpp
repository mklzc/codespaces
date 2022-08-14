#include <bits/stdc++.h>
const int Maxn = 15;
int digit[Maxn], cnt;
int f[Maxn][Maxn];
int dfs(int pos, bool limit, bool prez, int lst)
{
    if (!pos) return (prez != true);
    if (!limit && !prez && ~f[pos][lst]) return f[pos][lst];
    int up = limit ? digit[pos] : 9, res = 0;
    for (int i = 0; i <= up; i++)
    {
        if (std::abs(i - lst) < 2) continue;
        if (prez && !i) res += dfs(pos - 1, limit && i == up, true, -2);
        else res += dfs(pos - 1, limit && i == up, false, i);
    }
    if (!limit && !prez) f[pos][lst] = res;
    return res;
}
int solve(int x)
{
    cnt = 0;
    memset(f, -1, sizeof(f));
    while (x)
        digit[++cnt] = x % 10, x = x / 10;
    return dfs(cnt, true, true, -2);
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", solve(b) - solve(a - 1));
    return 0;
}