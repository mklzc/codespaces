#include <bits/stdc++.h>
const int Maxn = 1e4 + 5, Maxm = 1e5 + 5;
int n, m, b, id[Maxn];
struct Query
{
    int val, id;
    friend bool operator <(const Query x, const Query y)
    {return x.val < y.val;}
} f[Maxn];
int head[Maxn], ver[Maxm], Next[Maxm], edge[Maxm], idx;
std::priority_queue<std::pair<int, int>> q;
int d[Maxn], v[Maxn];
void add(int x, int y, int z)
{
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
bool dijkstra(int pos)
{
    if (id[1] > pos) return false;
    memset(d, 0x3f, sizeof(d));
    memset(v, 0,sizeof(v));
    d[1] = 0;
    q.emplace(0, 1);
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z && id[y] <= pos)
                d[y] = d[x] + z, q.emplace(-d[y], y);
        }
    }
    return (d[n] <= b);
}
int main()
{
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 1, x; i <= n; i++)
        scanf("%d", &x), f[i] = (Query){x, i};
    for (int i = 1, x, y, z; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    std::sort(f + 1, f + n + 1);
    for (int i = 1; i <= n; i++) id[f[i].id] = i;
    int l = 1, r = n, ans = n + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (dijkstra(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (ans == n + 1) return printf("AFK"), 0;
    printf("%d", f[ans].val);
    return 0;
}