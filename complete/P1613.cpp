// url: https://www.luogu.com.cn/problem/P1613
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#define rep(VAR, ST, ED) for (int VAR = ST; VAR <= ED; VAR++)
const int N = 55;
int n, m;
std::vector<std::pair<int, int>> G[N];
int d[N][N][65], dist[N];
bool st[N];
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    std::queue<int> q;
    dist[1] = 0, st[1] = true, q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop(), st[x] = false;
        for (auto y : G[x])
            if (dist[y.first] > dist[x] + y.second)
            {
                dist[y.first] = dist[x] + y.second;
                if (!st[y.first]) q.push(y.first), st[y.first] = true;
            }
    }
    return dist[n];
}

int main()
{
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &u, &v), d[u][v][0] = 1, G[u].emplace_back(v, 1);
    rep(k, 1, 64) rep(t, 1, n) rep(i, 1, n) rep(j, 1, n){
        if (d[i][t][k - 1] && d[t][j][k - 1]) d[i][j][k] = 1, G[i].emplace_back(j, 1);
    }
    printf("%d\n", spfa());
    return 0;
}