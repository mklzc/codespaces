//url: https://www.luogu.com.cn/problem/P4980
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
const int N = 1e5 + 5, mod = 1e9 + 7;
using LL = long long;
LL fac[N], cnt;
class OP
{
public:
    void split(int x)
    {
        cnt = 0;
        LL i = 1;
        for (; i * i <= x; i++)
        {
            if (x % i)
                continue;
            fac[++cnt] = i;
            if (x / i != i)
                fac[++cnt] = x / i;
        }
    }
    LL phi(LL x)
    {
        LL i = 2, res = x;
        for (; i * i <= x; i++)
            if (!(x % i))
            {
                res = res * (i - 1) / i;
                while (x % i == 0)
                    x /= i;
            }
        if (x > 1)
            return res * (x - 1) / x;
        return res;
    }
    LL qpow(LL x, LL y)
    {
        LL res = 1;
        for (; y; y >>= 1)
        {
            if (y & 1)
                res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
} op;
int main()
{
    int T;
    read(T);
    while (T--)
    {
        LL res = 0, n;
        read(n);
        op.split(n);
        for (int i = 1; i <= cnt; i++)
        {
            int d = fac[i];
            res = (res + op.qpow(n, d - 1) * op.phi(n / d) % mod) % mod;
        }
        write(res), putchar('\n');
    }
    return 0;
}