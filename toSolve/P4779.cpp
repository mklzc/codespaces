#include <bits/stdc++.h>
const int Maxn = 1e5 + 5, Maxm = 2e5 + 5;
int head[Maxn], Next[Maxm], ver[Maxm], edge[Maxm], idx;
int v[Maxn], d[Maxn];
int n, m, s;
std::priority_queue<std::pair<int, int>> q;
void add(int x, int y, int z)
{
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
void dijkstra(int rt)
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    q.emplace(0, rt), d[rt] = 0;
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        // std::cerr << x << " ";
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z)
                d[y] = d[x] + z, q.emplace(-d[y], y);
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i]);
    return 0;
}