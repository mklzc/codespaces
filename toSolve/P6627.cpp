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
const int N = 1;
int n;
struct Tre
{
    int l, r;
    int val, add;
}t[30][N];
int idx;
int build(int p, int l, int r)
{
    if (l == r)
    {
    }
    t[p].l = build();
    return p;
}
void Build()
{
    for (int i = 0; i <= 30; i++)
    {
    }
}
int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
    }
    return 0;
}