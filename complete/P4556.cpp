#include <bits/stdc++.h>
const int Maxn = 1e5 + 5, SCP = 1e5;
int n, m, rt[Maxn], ans[Maxn], tot;
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1], idx;
int fa[Maxn], dep[Maxn], top[Maxn], son[Maxn], sz[Maxn];
struct Segment {
    int l, r, Max, id;
} t[Maxn * 80];
void add(int x, int y) { ver[++idx] = y, Next[idx] = head[x], head[x] = idx; }
void dfs1(int x, int fah)
{
    fa[x] = fah, dep[x] = dep[fah] + 1, sz[x] = 1;  
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (y == fa[x]) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[son[x]] < sz[y]) son[x] = y;
    }
}
void dfs2(int x, int tp)
{
    top[x] = tp;
    if (!son[x]) return;
    dfs2(son[x], tp);
    for (int i = head[x]; i; i = Next[i])
        if (ver[i] != fa[x] && ver[i] != son[x]) dfs2(ver[i], ver[i]);
}
int lca(int u, int v)
{
    for (; top[u] != top[v]; u = fa[top[u]])
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    return dep[u] < dep[v] ? u : v;
}
#define ls t[p].l
#define rs t[p].r
inline void pushup(int p)
{
    if (t[ls].Max >= t[rs].Max)
        t[p].Max = t[ls].Max, t[p].id = t[ls].id;
    else t[p].Max = t[rs].Max, t[p].id = t[rs].id;
}
void modify(int &p, int l, int r, const int pos, const int val)
{
    if (!p) p = ++tot;
    if (l == r) return t[p].Max += val, t[p].id = l, void();
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls, l, mid, pos, val);
    else modify(rs, mid + 1, r, pos, val);
    pushup(p);
}
int merge(int l, int r, int x, int y)
{
    if (!x || !y) return x | y;
    if (l == r) return t[x].Max += t[y].Max, t[x].id = l, x;
    int mid = (l + r) >> 1;
    t[x].l = merge(l, mid, t[x].l, t[y].l);
    t[x].r = merge(mid + 1, r, t[x].r, t[y].r);
    return pushup(x), x;
}
void dfs(int x)
{
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (y == fa[x]) continue;
        dfs(y);
        rt[x] = merge(1, SCP, rt[x], rt[y]);
    }
    if (t[rt[x]].Max) ans[x] = t[rt[x]].id;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, x, y; i <= n - 1; i++)
    {
        scanf("%d %d", &x, &y);
        add(x, y), add(y, x), rt[i] = ++tot;
    }
    rt[n] = ++tot, dfs1(1, 0), dfs2(1, 0);
    int x, y, z;
    while (m--)
    {    
        scanf("%d %d %d", &x, &y, &z);
        int d = lca(x, y);
        modify(rt[x], 1, SCP, z, 1);
        modify(rt[y], 1, SCP, z, 1);
        modify(rt[d], 1, SCP, z, -1);
        if (fa[d]) modify(rt[fa[d]], 1, SCP, z, -1);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}