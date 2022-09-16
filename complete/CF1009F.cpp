#include <bits/stdc++.h>
const int Maxn = 1e6 + 5;
std::vector<int> G[Maxn];
int res[Maxn], dep[Maxn], son[Maxn], ans[Maxn], buf[Maxn], n;
int *f[Maxn], *now = buf;
void dfs1(int x, int fa)
{
    for (int y : G[x])
    {
        if (y == fa) continue;
        dfs1(y, x);
        if (dep[son[x]] < dep[y]) son[x] = y;
    }
    dep[x] = dep[son[x]] + 1;
}
void dfs2(int x, int fa)
{
    f[x][0] = 1;
    if (son[x])
    {
        f[son[x]] = f[x] + 1;
        dfs2(son[x], x);
        ans[x] = ans[son[x]] + 1;
    }
    for (int y : G[x])
    {
        if (y == son[x] || y == fa) continue;
        f[y] = now, now += dep[y];
        dfs2(y, x);
        for (int i = 1; i <= dep[y]; i++)
        {
            f[x][i] += f[y][i - 1];
            if (f[x][ans[x]] < f[x][i] || (f[x][ans[x]] == f[x][i] && ans[x] > i))
                ans[x] = i;
        }
    }
    if (f[x][ans[x]] == 1) ans[x] = 0;
}
int main()
{
    std::cin >> n;
    for (int i = 1, u, v; i <= n - 1; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs1(1, 0);
    f[1] = now, now += dep[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}