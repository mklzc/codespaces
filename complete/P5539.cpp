#include <bits/stdc++.h>
#define rep(_var, st, ed) for (int _var = st; _var <= ed; _var++)
using LL = long long;
const int N = 1005, mod = 998244353;
LL inv[N], fac[N], f1[N], f2[N], ans;
int a, b, c, d, n, scp;
inline LL C(int x, int y) {return (fac[x] * inv[y] % mod) * inv[x - y] % mod;}
inline int sign(int x) { return (x & 1) ? -1 : 1; }
inline void init_ifac(int scp)
{
    inv[1] = fac[1] = inv[0] = fac[0] = 1;
    rep(i, 2, scp)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod,
        fac[i] = fac[i - 1] * i % mod;
    rep(i, 2, scp)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
inline void init(int &x, int &y, LL *f)
{
    x -= scp, y -=scp;
    rep(i, 0, x) rep(j, 0, y)
        f[i + j] = (f[i + j] + inv[i] * inv[j] % mod) % mod;
}
inline void op(int &x, int &y, LL *f)
{
    rep(i, 0, y - 1)
        f[i + x] = (f[i + x] + inv[x] * inv[i]) % mod;
}
int main()
{
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    init_ifac(n);
    scp = std::min(std::min(std::min(a, b), std::min(c, d)), n / 4);
    init(a, b, f1), init(c, d, f2);
    for (int k = scp; k >= 0; k--)
    {
        LL buf = 0;
        int sav = n - 4 * k;
        rep(i, 0, sav)
            buf = (buf + f1[i] * f2[sav - i] % mod) % mod;
        ans = (ans + (sign(k) * buf * fac[sav] % mod) * C(n - 3 * k, k) % mod) % mod;
        a++, b++, c++, d++;
        op(a, b, f1), op(b, a, f1), op(c, d, f2), op(d, c, f2);
        f1[a + b] = (f1[a + b] + inv[a] * inv[b] % mod) % mod;
        f2[c + d] = (f2[c + d] + inv[c] * inv[d] % mod) % mod;
    }
    printf("%lld\n", (ans % mod + mod) % mod);
    return 0;
}