// url: https://www.luogu.com.cn/problem/P7960
#include <cstdio>
#include <bitset>
#include <iostream>
#define filein freopen("in", "r", stdin)
#define fileout freopen("out", "w", stdout)
class IO
{
public:
    template <class Tp>
    void read(Tp &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
} io;
class Main
{
public:
    static const int N = 1e7 + 5;
    int T, x;
    int vis[N], num[N];
    bool check(int a);
    void Init(void);
    void Readexe(void);
} work;
void Main::Init()
{
    for (int i = 7; i < N; i++)
        if (!vis[i] && check(i))
            for (int j = 1; j <= N / i; j++)
                vis[i * j] = 1;
    for (int i = 1; i < N; i++)
    {
        if (!vis[i + 1]) num[i] = i + 1;
        if (!vis[i] && vis[i - 1])
        {
            int flag = 0;
            for (int j = i - 1; flag != 1 && j >= 1; j--)
            {
                if (!vis[j] && vis[j - 1])
                    flag = 1;
                if (!num[j]) num[j] = i;
            }
        }
    }
}
bool Main::check(int a)
{
    while (a)
    {
        int b = a % 10;
        if (b == 7)
            return true;
        a = a / 10;
    }
    return false;
}
void Main::Readexe()
{
    io.read(T);
    Init();
    while (T--)
    {
        io.read(x);
        if (vis[x])
            puts("-1");
        else
            printf("%d\n", num[x]);
    }
}
int main()
{
    work.Readexe();
    return 0;
}