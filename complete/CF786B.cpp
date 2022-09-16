#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 1e5 + 5, MaxNode = Maxn << 3;
int n, Q, s, idx;
int rtf, rts;
struct Node { int to, val; Node(int _to, int _val) : to(_to), val(_val) {}};
std::vector<Node> G[MaxNode];
struct Seg { int l, r; } tf[Maxn << 2], ts[Maxn << 2];
void add(int x, int y, int z) { G[x].emplace_back(y, z); }
void build(int &p, int &q, int l, int r)
{
    if (l == r) return p = l, q = l, void();
    p = ++idx, q = ++idx;
    int mid = (l + r) >> 1;
    build(tf[p].l, ts[q].l, l, mid);
    build(tf[p].r, ts[q].r, mid + 1, r);
    add(p, tf[p].l, 0), add(p, tf[p].r, 0);
    add(ts[q].l, q, 0), add(ts[q].r, q, 0);
}
int ql, qr, node, val;
void modify(int p, int q, int l, int r, const int tp)
{
    if (ql <= l && r <= qr)
        return tp ? add(q, node, val) : add(node, p, val);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(tf[p].l, ts[q].l, l, mid, tp);
    if (mid < qr)
        modify(tf[p].r, ts[q].r, mid + 1, r, tp);
}
std::priority_queue<std::pair<LL, int>> q;
LL dist[MaxNode]; int vis[MaxNode];
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    q.emplace(0, s), dist[s] = 0;
    while (!q.empty())
    {
        int x = q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto son : G[x])
        {
            int y = son.to, z = son.val;
            if (dist[y] > dist[x] + z)
                dist[y] = dist[x] + z, q.emplace(-dist[y], y);
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &Q, &s);
    idx = n;
    build(rtf, rts, 1, n);
    int opt, u, v, w;
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d", &opt);
        if (opt == 1)
            scanf("%d %d %d", &u, &v, &w), add(u, v, w);
        else
        {
            scanf("%d %d %d %d", &node, &ql, &qr, &val);
            modify(rtf, rts, 1, n, opt - 2);
        }
    }
    dijkstra();
    const LL INF = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
        printf("%lld ", dist[i] != INF ? dist[i] : -1);
    return 0;
}