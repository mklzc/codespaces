#include <bits/stdc++.h>
const int Maxn = 5e3 + 5;
int n, m;
int head[Maxn], Next[Maxn], ver[Maxn], edge[Maxn], idx;
void add(int x, int y, int z)
{
    ver[++idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}
int d[Maxn], c[Maxn], vis[Maxn];
bool spfa()
{
    memset(d, 0x3f, sizeof(d));
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i), vis[i] = true, d[i] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = head[x]; ~i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z)
            {
                d[y] = d[x] + z, c[y] = c[x] + 1;
                if (!vis[y])
                    q.push(y), vis[y] = true;
                if (c[y] > n - 1) return false;
            }
        }
    }
    return true;
}
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1, x1, x2, z; i <= m; i++)
    {
        scanf("%d %d %d", &x1, &x2, &z);
        add(x2, x1, z);
    }
    if (!spfa()) return puts("NO"), 0;  
    for (int i = 1; i <= n; i++)
        printf("%d\n", d[i]);
    return 0;
}