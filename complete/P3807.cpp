#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0; T w = 1;
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
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
using LL = long long;
const int N = 1e5 + 6;
LL inv[N], fac[N], n, m, mod;
inline LL C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
}
inline void init_ifac(int scp)
{
    inv[1] = fac[1] = inv[0] = fac[0] = 1;
    rep(i, 2, scp)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod,
        fac[i] = fac[i - 1] * i % mod;
    rep(i, 2, scp)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
LL lucas(LL x, LL y)
{
    if (!y) return 1;
    return C(x % mod, y % mod) * lucas(x / mod, y / mod) % mod;
}
int main()
{
    int T;read(T);
    while (T--)
    {
        read(n, m, mod);
        init_ifac(mod);
        printf("%lld\n", lucas(n + m, m));
    }
	return 0;
}