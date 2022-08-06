#include <bits/stdc++.h>
namespace IO{
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
    inline void read(T &x, Args&... args)
    {
        read(x);
        read(args...);
    }
};
using IO::read;
const int Maxn = 5e6 + 5;
int n, k, mod, a[Maxn], s[Maxn] = {1}, invs[Maxn];
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
    }
    return res;
}
int main()
{
    read(n, mod, k);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        s[i] = 1ll * s[i - 1] * a[i] % mod;
    }
    invs[n] = qpow(s[n], mod - 2);
    for (int i = n - 1; i >= 1; i--)
        invs[i] = 1ll * invs[i + 1] * a[i + 1] % mod;
    int buf = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        buf = 1ll * buf * k % mod;
        int inv = 1ll * invs[i] * s[i - 1] % mod;
        ans = (ans + 1ll * buf * inv) % mod;
    }
    printf("%d\n", ans);
    return 0;
}