#include <bits/stdc++.h>
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
using LL = long long;
const int mod = 998244353, Maxn = 1005;
LL n, p, f[Maxn];
int chose[Maxn], idx, sav, xs[Maxn];
LL qpow(LL x, LL y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void dfs(int i, int x, int tot)
{
    if (idx == i || x == n + 1)
    {
        if (idx < i) return;
        int buf = 0;
        for (int j = 1; j <= idx; j++)
            buf += chose[j] - j;
        if (buf == tot) sav++;
        return;
    }
    chose[++idx] = x;
    dfs(i, x + 1, tot);
    idx--;
    dfs(i, x + 1, tot);
}
inline int calc_xs(int i, int scp, int s)
{
    if (xs[scp - s]) return xs[scp - s];
    sav = idx = 0;
    memset(chose, 0, sizeof(chose));
    dfs(i, 1, s);
    xs[s] = xs[scp - s] = sav;
    return sav;
}
inline LL calc(int i)
{
    if (f[n - i]) return f[n - i];
    int scp = i * (n - i);
    LL res = 0;
    for (int s = 0; s <= scp; s++)
    {
        int XS = calc_xs(i, scp, s);
        res = (res + (XS * qpow(p, scp - s) % mod) * qpow(1 - p, s)) % mod;
    }
    return (res % mod + mod) % mod;
}
int main()
{
    freopen("noip.in", "r", stdin);
    freopen("noip.out", "w", stdout);
    scanf("%lld %lld", &n, &p);
    if (n == 2)
        return puts("1"), 0;
    LL ans = 0, fac = 1;
    for (int i = 1; i <=  n - 1; i++)
    {
        memset(xs, 0, sizeof(xs));
        fac = fac * i % mod;
        f[i] = calc(i);
        ans = (ans +  f[i] * fac) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}