//url: https://www.luogu.com.cn/problem/P1880
#include <bits/stdc++.h>
namespace io
{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args &...args)
    {
        read(x);
        read(args...);
    }
    template <typename T>
    inline void write(T x)
    {
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + 48);
    }
};
using namespace io;
const int N = 210;
int n, a[N], s[N], f[N][N], g[N][N];
int main()
{
    read(n);
    for (int i = 1; i <= n + n; i++)
    {
        if (i <= n) read(a[i]), a[i + n] = a[i];
        s[i] = s[i - 1] + a[i];
    }
    auto sum = [&](int x, int y)->int{return s[x] - s[y - 1];};
    for (int p = 1; p < n; p++)
    {
        for (int i = 1; i + p < n + n && i < n + n; i++)
        {
            int j = i + p;
            g[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++)
                f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j] + sum(j, i)),
                g[i][j] = std::min(g[i][j], g[i][k] + g[k + 1][j] + sum(j, i));
        }
    }
    int Max = 0, Min = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        Max = std::max(Max, f[i][i + n - 1]), 
        Min = std::min(Min, g[i][i + n - 1]);
    write(Min);
    putchar('\n');
    write(Max);
    return 0;
}