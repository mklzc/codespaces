#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
using LL = long long;
struct Node {
    int to; LL val;
    Node(int _to = 0, LL _val = 0) : to(_to), val(_val) {}
};
struct State {
    int node; LL dist;
    State(int _node = 0, LL _dist = 0) : node(_node), dist(_dist) {}
    friend bool operator <(const State x, const State y)
    {  return x.dist > y.dist; }
};
std::vector<Node> Z[Maxn], F[Maxn];
int T, n, m, k, sav[Maxn];
int v[Maxn], orf[Maxn], ors[Maxn];
LL df[Maxn], ds[Maxn];
std::priority_queue<State> q;
void add(int x, int y, LL z)
{
    Z[x].emplace_back(y, z);
    F[y].emplace_back(x, z);
}
const int INF = 0x3f3f3f3f3f3f3f3f;
void dijkstra(std::vector<Node> *G, LL *dist, int *origin)
{
    memset(v, 0, sizeof(v));
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    for (int i = 1; i <= k; i++)
    {
        q.emplace(sav[i], 0);
        origin[sav[i]] = sav[i];
        dist[sav[i]] = 0;
    }
    while (!q.empty())
    {
        int x = q.top().node;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (auto state : G[x])
        {
            int y = state.to, z = state.val;
            if (dist[x] + z < dist[y])
            {
                origin[y] = origin[x];
                dist[y] = dist[x] + z;
                q.emplace(y, dist[y]);
            }
        }
    }
}
void solve()
{
    for (int i = 1; i < Maxn; i++)
        Z[i].clear(), F[i].clear();
    memset(orf, 0, sizeof(orf));
    memset(ors, 0, sizeof(ors));
    scanf("%d %d %d", &n, &m, &k);
    int x, y; LL z;
    for (int i = 1; i <= m; i++)
        scanf("%d %d %lld", &x, &y, &z), add(x, y, z);
    for (int i = 1; i <= k; i++)
        scanf("%d", &sav[i]);
    dijkstra(Z, df, orf);
    dijkstra(F, ds, ors);
    LL ans = INF;
    for (int i = 1; i <= n; i++)
        for (auto state : Z[i])
            if (orf[i] != ors[state.to])
                ans = std::min(ans, df[i] + state.val + ds[state.to]);
    printf("%lld\n", ans);
}
int main()
{
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}