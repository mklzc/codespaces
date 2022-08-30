#include <bits/stdc++.h>
const int Maxn = 1e4 + 5, Maxm = 5e4 + 5, Maxk = 11;
int n, m, s, t, k;
int head[Maxn], Next[Maxm << 1], ver[Maxm << 1], edge[Maxm << 1], idx;
void add(int x, int y, int z)
{
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
int d[Maxn][Maxk], v[Maxn][Maxk];
struct Node {
    int dist, node, cnt;
    Node(int _dist = 0, int _node = 0, int _cnt = 0)
    { dist = _dist, node = _node, cnt = _cnt; }
    friend bool operator<(const Node x, const Node y)
    { return x.dist > y.dist; }
};
std::priority_queue<Node> q;
int dijkstra(int st, int ed)
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[st][0] = 0;
    q.emplace(0, st, 0);
    while (!q.empty())
    {
        auto state = q.top();
        q.pop();
        int x = state.node, cnt = state.cnt;
        if (v[x][cnt]) continue;
        v[x][cnt] = 1;
        for (int i = head[x]; ~i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (cnt < k && d[x][cnt] < d[y][cnt + 1])
                d[y][cnt + 1] = d[x][cnt],
                q.emplace(d[y][cnt + 1], y, cnt + 1);
            if (d[x][cnt] + z < d[y][cnt])
                d[y][cnt] = d[x][cnt] + z,
                q.emplace(d[y][cnt], y, cnt);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; i++)
        ans = std::min(d[ed][i], ans);
    return ans;
}
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &n, &m, &k);
    scanf("%d %d", &s, &t);
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    printf("%d\n", dijkstra(s, t));
    return 0;
}