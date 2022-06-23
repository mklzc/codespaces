#include <bits/stdc++.h>
#define filein freopen("in", "r", stdin)
#define filout freopen("out", "w", stdout)
class IO
{
public:
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
    inline void read(T &x, Args &...args)
    {
        read(x);
        read(args...);
    }
    template <typename T>
    inline void write(T x)
    {
        char F[200];
        T tmp = x > 0 ? x : -x;
        if (x < 0)
            putchar('-');
        int cnt = 0;
        while (tmp > 0)
            F[cnt++] = tmp % 10 + '0', tmp /= 10;
        while (cnt > 0)
            putchar(F[--cnt]);
    }
} io;
class Main
{
public:
    int L, R, k;
    int l, r, ans = 0;
    void Read()
    {
        io.read(L, R, k);
        l = L * k, r = R * k;
    }
    void dfs(int cnt, int x)
    {
        if (cnt == k)
            return void(ans++);
        for (int i = x; i <= R; i++)
            dfs(cnt + 1, i);
    }
    void Run()
    {
        for (int i = L; i <= R; i++)
            dfs(1, i);
        io.write(ans);

    }
}work;
int main()
{
    filein;
    work.Read();
    work.Run();
    putchar('\n');
    return 0;
}