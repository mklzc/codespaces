#include <bits/stdc++.h>
const int Maxn = 2010;
int n, m, d[Maxn], len[Maxn];
struct Node {
    int u, v;
} t[Maxn];
struct Spfa {
    int to, w;
    Spfa(int _to, int _w) : to(_to), w(_w) {}
};
std::bitset<Maxn> vis1, vis2, v;
std::vector<int> Z[Maxn], F[Maxn];
std::vector<Spfa> G[Maxn];
std::queue<int> q;
void dfs(int x, std::vector<int> *Gr, std::bitset<Maxn> &vis)
{
    vis[x] = 1;
    for (int y : Gr[x])
        if (!vis[y]) dfs(y, Gr, vis);
}
bool spfa()
{
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++)
        q.push(i), d[i] = 0, v[i] = 1;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        v[x] = 0;
        for (auto now : G[x])
        {
            int y = now.to, z = now.w;
            if (d[y] > d[x] + z)
            {
                d[y] = d[x] + z, len[y] = len[x] + 1;
                if (!v[y]) q.push(y), v[y] = 1;
                if (len[y] > n - 1) return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &t[i].u, &t[i].v);
        Z[t[i].u].push_back(t[i].v);
        F[t[i].v].push_back(t[i].u);
    }
    dfs(1, Z, vis1), dfs(n, F, vis2);
    if (!vis1[n])
        return puts("-1"), 0;
    for (int i = 1; i <= m; i++)
        if (vis1[t[i].u] && vis2[t[i].v])
        {
            G[t[i].u].emplace_back(t[i].v, 9);
            G[t[i].v].emplace_back(t[i].u, -1);
        }
    if (!spfa())
        return puts("-1"), 0;
    else
    {
        printf("%d %d\n", n, m);
        for (int i = 1; i <= m; i++)
        {
            if (vis2[t[i].v] && vis1[t[i].u])
                printf("%d %d %d\n", t[i].u, t[i].v, std::abs(d[t[i].u] - d[t[i].v]));
            else
                printf("%d %d 1\n", t[i].u, t[i].v);
        }
    }
    return 0;
}