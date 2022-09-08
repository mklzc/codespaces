#include <bits/stdc++.h>
const int Maxm = 400010, Maxn = 200010, BZ = 19;
int T, n, m, idx;
int fa[Maxm], w[Maxm], Min[Maxm], f[Maxm][20];
int d[Maxn], v[Maxn]; // clear
struct Edge { int u, v, l, a; } t[Maxm];
struct Node { int to, val; Node(int _to, int _val) : to(_to), val(_val) {} };
std::vector<Node> G[Maxn];
std::vector<int> Gt[Maxm];
std::priority_queue<std::pair<int, int>> q;
void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    q.emplace(0, 1), d[1] = 0;
    while (!q.empty())
    {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (auto node : G[x])
        {
            int y = node.to, z = node.val;
            if (d[y] > d[x] + z)
                d[y] = d[x] + z, q.emplace(-d[y], y);
        }
    }
}
bool operator <(Edge x, Edge y) { return x.a > y.a; }
inline int get(int x) { return (x != fa[x]) ? (fa[x] = get(fa[x])) : x; }
void build()
{
    std::iota(fa + 1, fa + n * 2, 1);
    std::sort(t + 1, t + m + 1);
    idx = n;
    for (int i = 1; i <= n << 1; i++) Gt[i].clear();
    auto merge = [](int x, int y, int z)
    {
        x = get(x), y = get(y);
        if (x == y) return;
        w[++idx] = z, fa[x] = fa[y] = idx;
        Gt[idx].emplace_back(x);
        Gt[idx].emplace_back(y);
    };
    for (int i = 1; i <= m; i++)
        merge(t[i].u, t[i].v, t[i].a);
}
void dfs(int x, int Fa)
{
    Min[x] = 0x3f3f3f3f;
    if (!Gt[x].size()) Min[x] = d[x];
    f[x][0] = Fa;
    for (int i = 1; i <= BZ; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int y : Gt[x])
        dfs(y, x), Min[x] = std::min(Min[x], Min[y]);
}
int query(int x, int p)
{
    for (int i = 19; i >= 0; i--)
        if (w[f[x][i]] > p) x = f[x][i];
    return Min[x];
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++)
            scanf("%d %d %d %d", &t[i].u, &t[i].v, &t[i].l, &t[i].a), 
            G[t[i].u].emplace_back(t[i].v, t[i].l),
            G[t[i].v].emplace_back(t[i].u, t[i].l);
        dijkstra(), build(), dfs(idx, 0);
        int Q, K, S, st, p, lst = 0;
        scanf("%d %d %d", &Q, &K, &S);
        while (Q--)
        {
            scanf("%d %d", &st, &p);
            lst = query((st + K * lst - 1) % n + 1, (p + K * lst) % (S + 1));
            printf("%d\n", lst);
        }
    }
    return 0;
}