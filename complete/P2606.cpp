#include <bits/stdc++.h>
#define int long long
const int Maxn = 1e6 + 5;
int t[Maxn << 1], n, mod;
int fac[Maxn], ifac[Maxn];
int C(int x, int y)
{
    if (x < 0 || y < 0 || x < y) return 0;
    return (int)((1ll * fac[x] * ifac[x - y] % mod) * ifac[y] % mod);
}
int lucas(int x, int y)
{
    if (y == 0) return 1;
    return (int)(1ll * lucas(x / mod, y / mod) * C(x % mod, y % mod) % mod);
}
void init(int scp, int mod)
{
    fac[1] = fac[0] = ifac[1] = ifac[0] = 1;
    for (int i = 2; i <= scp; i++)
        fac[i] = fac[i - 1] * i % mod,
        ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
    for (int i = 2; i <= scp; i++)
        ifac[i] = ifac[i - 1] * ifac[i] % mod;
}
void build(int p)
{
    if (p <= n) t[p] = 1;
    if (p >= n) return;
    build(p << 1);
    build(p << 1 | 1);
    t[p] += t[p << 1] + t[p << 1 | 1];
}
int dfs(int p)
{
    if (t[p] == 0) return 1;
    return (1ll * lucas(t[p] - 1, t[p << 1]) * dfs(p << 1) % mod) * dfs(p << 1 | 1) % mod;
}
signed main()
{
    scanf("%lld %lld", &n, &mod);
    init(Maxn - 1, mod);
    build(1);
    printf("%lld\n", dfs(1));
    return 0;
}