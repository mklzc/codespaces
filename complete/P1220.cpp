// https://www.luogu.com.cn/problem/P1220
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
const int N = 100;
int n, c, d[N], p[N], f[N][N][2], s[N];
namespace Main{
    void Read()
    {
        read(n, c);
        for (int i = 1; i <= n; i++)
        {
            read(d[i], p[i]);
            s[i] = s[i - 1] + p[i];
        }
    }
    void Run()
    {
        auto Min = [](int x, int y)->int{return x > y ? x : y;};
        auto Max = [](int x, int y)->int{return x < y ? x : y;};
        auto calc = [](int i, int j, int l, int r)->int{
            return (d[j] - d[i]) * (s[n] - s[r - 1] + s[l]);
        };
        memset(f, 0xf, sizeof(f));
        f[c][c][1] = f[c][c][0] = 0;
        for (int j = c; j <= n; j++)
        {
            for (int i = j - 1; i >= 1; i--)
            {
                f[i][j][0] = Max(f[i + 1][j][0] + calc(i, i + 1, i, j + 1), f[i + 1][j][1] + calc(i, j, i, j + 1));
                f[i][j][1] = Max(f[i][j - 1][0] + calc(i, j, i - 1, j), f[i][j - 1][1] + calc(j - 1, j, i - 1, j));
            }
        }
        write(Max(f[1][n][0], f[1][n][1]));
    }
};
using namespace Main;
int main()
{
    Read();
    Run();
    return 0;
}