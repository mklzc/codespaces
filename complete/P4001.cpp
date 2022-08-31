#include <bits/stdc++.h>
const int Maxn = 3 * 1010 * 1010;
int n, m, ex_up, ex_down;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], edge[Maxn << 1], idx;
int d[Maxn], v[Maxn];
std::priority_queue<std::pair<int, int>> q;
#define down true
#define up false
inline void add(int x, int y, int z)
{
    // if (idx & 1) std::cout << x << " " << y << " " << z << "\n";
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
inline void add_edge(int x, int y, int z) { add(x, y, z), add(y, x, z); }
inline int get_pos(int x, int y, bool side)
{
    if (side == up) return (x - 1) * (m - 1) * 2 + y;
    else return (x - 1) * (m - 1) * 2 + m - 1 + y;
}
inline void addh(int i, int j, int z)
{
    if (i == 1) return add_edge(ex_up, get_pos(1, j, up), z);
    if (i == n) return add_edge(ex_down, get_pos(n - 1, j, down), z);
    int xid = get_pos(i - 1, j, down), yid = get_pos(i, j, up);
    add_edge(xid, yid, z);
}
inline void adds(int i, int j, int z)
{
    if (j == 1) return add_edge(ex_down, get_pos(i, 1, down), z);
    if (j == m) return add_edge(ex_up, get_pos(i, m - 1, up), z);
    int xid = get_pos(i, j - 1, up), yid = get_pos(i, j, down);
    add_edge(xid, yid, z);
}
inline void addx(int i, int j, int z)
{
    int xid = get_pos(i, j, down), yid = get_pos(i, j, up);
    add_edge(xid, yid, z);
}
#undef down
#undef up
inline int dijkstra(int st, int ed)
{
    memset(v, 0, sizeof(v)), memset(d, 0x3f, sizeof(d));
    q.emplace(0, st), d[st] = 0;
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z)
                d[y] = d[x] + z, q.emplace(-d[y], y);
        }
    }
    return d[ed];
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d %d", &n, &m);
    ex_up = (n - 1) * (m - 1) * 2 + 1;
    ex_down = (n - 1) * (m - 1) * 2 + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1, x; j <= m - 1; j++)
            scanf("%d", &x), addh(i, j, x);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1, x; j <= m; j++)
            scanf("%d", &x), adds(i, j, x);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1, x; j <= m - 1; j++)
            scanf("%d", &x), addx(i, j, x);
    // std::cout << idx << "\n";
    printf("%d\n", dijkstra(ex_up, ex_down));
    return 0;
}