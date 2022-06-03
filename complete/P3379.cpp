// url: https://www.luogu.com.cn/problem/P3379
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, s, f[N][20], d[N];
vector<int> G[N];
inline void bfs(int rt)
{
    queue<int> q;
    q.push(rt), d[rt] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : G[x])
            if (!d[y])
            {
                q.push(y);
                f[y][0] = x, d[y] = d[x] + 1;
                for (int i = 1; i <= 18; i++)
                    f[y][i] = f[f[y][i - 1]][i - 1];
            }
    }
}
inline int lca(int x, int y)
{
    if (d[x] > d[y]) swap(x, y);
    for (int i = 18; i >= 0; i--)
        if (d[x] <= d[f[y][i]]) y = f[y][i];
    if (x == y)
        return x;
    for (int i = 18; i >= 0; i--)
        if (f[x][i] != f[y][i]) 
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
inline void raw()
{
    scanf("%d %d %d", &n, &m, &s);
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        G[x].push_back(y), G[y].push_back(x);
    }
    bfs(s);
    while (m--)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
}
int main() { return raw(), 0; }