#include <bits/stdc++.h>
const int Maxn = 1010 * 1010;
int n, m;
struct Node {
    double x, y;
} t[Maxn];
double dis(double xf, double yf, double xs, double ys)
{
    double resf = std::fabs(xf - xs), rest = std::fabs(yf - ys);
    resf = resf * resf, rest = rest * rest;
    return std::sqrt(std::fabs(resf + rest));
}
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1], idx;
double edge[Maxn << 1];
void add(int x, int y, double z)
{
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
std::priority_queue<std::pair<double, int>> q;
double dist[Maxn];
bool vis[Maxn];
void dijkstra()
{
    q.emplace(0, 0);
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i <= m + 1; ++i)
        dist[i] = 1e9;
    dist[0] = 0;
    // std::cout << "\n";
    while (!q.empty())
    {
        auto x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; ~i; i = Next[i])
        {
            int y = ver[i];
            double z = std::max(edge[i], dist[x]);
            if (z < dist[y])
            {
                dist[y] = z;
                q.emplace(-dist[y], y);
            }
        }
    }
    // for (int i = 0; i <= m + 1; i++)
    //     std::cout << dist[i] << " ";
    printf("%.2lf\n", dist[m + 1]);
}
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%lf %lf", &t[i].x, &t[i].y);
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
        {
            double sav = dis(t[i].x, t[i].y, t[j].x, t[j].y);
            // std::cout << i << " " << j << " " << sav << "\n";
            add(i, j, sav / 2.0);
            add(j, i, sav / 2.0);
        }
    for (int i = 1; i <= m; i++)
    {
        add(0, i, t[i].x);
        add(i, 0, t[i].x);
        add(m + 1, i, double(n) - t[i].x);
        add(i, m + 1, double(n) - t[i].x);
    }
    // puts("yes");
    dijkstra();
    return 0;
}