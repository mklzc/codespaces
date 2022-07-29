#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') { if (ch == '-') w = -1;ch = getchar();}
        while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;using LL = long long;

const int mod = 2333;
LL inv[mod + 10], fac[mod + 10], F[mod + 5][mod + 5];
int T;
inline LL C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
}
inline void init(int scp)
{
    inv[1] = fac[1] = inv[0] = fac[0] = 1;
    rep(i, 2, scp)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod,
        fac[i] = fac[i - 1] * i % mod;
    rep(i, 2, scp)
        inv[i] = inv[i] * inv[i - 1] % mod;
    rep(i, 0, mod - 1)
    {
        F[i][0] = 1;
        rep(j, 1, mod - 1)
            F[i][j] = (F[i][j - 1] + C(i, j)) % mod;
    }
}
LL lucas(LL x, LL y)
{
    if (!y) return 1;
    return lucas(x / mod, y / mod) * C(x % mod, y % mod) % mod;
}
LL rcurs(LL n, LL k)
{
    if (n < mod && k < mod) return F[n][k];
    return (rcurs(n / mod, k / mod - 1) * rcurs(n % mod, mod - 1) % mod + lucas(n / mod, k / mod) * rcurs(n % mod, k % mod) % mod) % mod;
}
int main()
{
    init(mod), read(T);
    while (T--)
    {
        LL n, k; read(n, k);
        printf("%lld\n", rcurs(n, k));
    }
    return 0;
}