#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
namespace io
{
    template <typename T>
    void read(T &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
    template <typename T, typename... Args>
    void read(T &x, Args&... args)
    {
        read(x);
        read(args...);
    }
    template <typename T>
    void write(T x)
    {
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + '0');
    }
};
using namespace io;
using LL = long long;
const int N = 1e5 + 5;
int n, m, sz[N], f[N];
std::vector<int> G[N];
std::queue<int> q;
int main()
{
    read(n, m);
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        read(a, b);
        G[a].push_back(b);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sz[i] = G[i].size();
        if (!sz[i]) q.push(sz[i]), f[i] = 1;
        // ans -= 1;
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : G[x])
        {
            sz[y]--, f[y] += f[x];
            if (!sz[y]) q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        ans += f[i];
    printf("%lld\n", ans);
    putchar('\n');
    return 0;
}