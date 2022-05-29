// url: https://www.luogu.com.cn/problem/P4644
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
    x = 0;
    T w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    x = x * w;
}
template <typename T, typename... Args>
inline void read(T &t, Args&... args)
{
    read(t);
    read(args...);
}

const int N = 86405;
int n, M, E, d[N];
int head[N], ver[N << 1], Next[N << 1], edge[N << 1], idx;
void add(int x, int y, int z)
{
    ver[++idx] = y, edge[idx] = z;
    Next[idx] = head[x], head[x] = idx;
}
priority_queue<pair<int, int> > q;
bool vis[N];
inline int work()
{
    memset(d, 0x3f, sizeof(d));
    q.push({0, M}), d[M] = 0;
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; ~i; i = Next[i])
        {
            int y = ver[i], z = edge[i];
            if (d[x] + z < d[y])
                d[y] = d[x] + z, q.push({-d[y], y});
        }
    }
    if (d[E + 1] != 0x3f3f3f3f)
        return d[E + 1];
    return -1;
}
inline void rai()
{
    memset(head, -1, sizeof(head));
    read(n, M, E);
    for (int i = 1; i <= n; i++)
    {
        int T1, T2, s;
        read(T1, T2, s);
        int u = (T1 < M) ? M: T1;
        int v = (T2 + 1 > E) ? E + 1: T2 + 1;
        add(u, v, s);
    }
    for (int i = M + 1; i <= E + 1; i++)
        add(i, i - 1, 0);
}
int main()
{
    rai();
    printf("%d\n", work());
    return 0;
}