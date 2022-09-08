#include <bits/stdc++.h>
const int Maxn = 5e5 + 10;
int n, m, s;
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1], idx;
int sz[Maxn], son[Maxn], top[Maxn], fa[Maxn], dep[Maxn];
void add(int x, int y)
{
    ver[++idx] = y;
    Next[idx] = head[x];
    head[x] = idx;
}
void dfs1(int x, int father)
{
    sz[x] = 1, fa[x] = father, dep[x] = dep[father] + 1;
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (y == father) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[son[x]] < sz[y]) son[x] = y;
    }
}
void dfs2(int x, int t)
{
    top[x] = t;
    if (!son[x]) return;
    dfs2(son[x], t);
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}
int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1, x, y; i <= n - 1; i++)
    {
        scanf("%d %d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs1(s, 0), dfs2(s, 0);
    int x, y;
    while (m--)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}