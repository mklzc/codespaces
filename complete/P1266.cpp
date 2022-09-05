#include <bits/stdc++.h>
const int Maxn = 155;
struct Node {
    int to, speed, lenth;
    Node(int _to, int _speed, int _lenth) : to(_to), speed(_speed), lenth(_lenth) {}
};
std::vector<Node> G[Maxn];
int n, m, ed;
double dist[Maxn][505];
bool v[Maxn][505];
struct Dijk {
    double dist;
    int speed, id;
    Dijk(double _dist, int _speed, int _id) : dist(_dist), speed(_speed), id(_id) {}
    friend bool operator <(const Dijk x, const Dijk y)
    { return x.dist > y.dist; }
};
std::priority_queue<Dijk> q;
std::pair<int, int> org[Maxn][505];
void dijkstra()
{
    auto div = [](int up, int down) ->double {
        return double(up) / double(down);
    };
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 500; j++)
            dist[i][j] = 1e9;
    q.emplace(0, 70, 0);
    dist[0][70] = 0;
    while (!q.empty())
    {
        auto now = q.top();
        int x = now.id;
        q.pop();
        if (v[x][now.speed]) continue;
        v[x][now.speed] = 1;
        for (auto Next : G[x])
        {
            int y = Next.to;
            double z = !Next.speed ? div(Next.lenth, now.speed) : div(Next.lenth, Next.speed);
            if (!Next.speed && dist[y][now.speed] > dist[x][now.speed] + z)
                dist[y][now.speed] = dist[x][now.speed] + z,
                q.emplace(dist[y][now.speed], now.speed, y),
                org[y][now.speed] = {x, now.speed};
            else if (Next.speed && dist[y][Next.speed] > dist[x][now.speed] + z)
                dist[y][Next.speed] = dist[x][now.speed] + z,
                q.emplace(dist[y][Next.speed], Next.speed, y),
                org[y][Next.speed] = {x, now.speed};
        }
    }
}
std::vector<int> ans;
int main()
{
    memset(org, -1, sizeof(org));
    scanf("%d %d %d", &n, &m, &ed);
    int x, y, sp, len;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %d", &x, &y, &sp, &len);
        G[x].emplace_back(y, sp, len);
    }
    
    dijkstra();
    double Min = 1e9; int pos = 0;
    for (int i = 1; i <= 500; i++)
        if(Min > dist[ed][i]) Min = dist[ed][i], pos = i;
    for (std::pair<int, int> now = {ed, pos}; ~now.first; now = org[now.first][now.second])
        ans.emplace_back(now.first);
    std::reverse(ans.begin(), ans.end());
    for (int path : ans)
        printf("%d ", path);
    printf("\n");
    return 0;
}