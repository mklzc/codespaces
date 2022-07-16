#define filein freopen("in", "r", stdin)
#define fileout freopen("out", "w", stdout)
#include <bits/stdc++.h>
using LL = long long;
const int N = 1e5 + 5, mod = 998244353;
int n, m, k;
LL fac[N], inv[N], phi[N], Invn;
int primes[N], v[N], cnt;
int PreWork()
{
    for (int i = 2; i < N; i++)
    {
        if (!v[i])
            primes[++cnt] = i, phi[i] = i - 1;
        for (int j = 1; j <= cnt && primes[j] * i < N; j++)
        {
            v[i * primes[j]] = 1;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    phi[1] = fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
        fac[i] = fac[i - 1] * i % mod,
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    Invn = inv[n];
    for (int i = 2; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
    return std::__gcd(n, m);
}

LL S(int n, int m)
{
    auto C = [&](int x, int y) -> LL
    { return fac[x] * inv[y] % mod * inv[x - y] % mod; };
    auto T = [&](int x, int y) -> LL
    { return C(x + y - 1, x - 1); };
    auto R = [&](int x, int y) -> LL
    {
        LL res = 0;
        int scope = std::min(y / (k + 1), x);
        for (int i = 0; i <= scope; i++)
            if (i & 1)
                res = (res - C(x, i) * T(x, y - i * (k + 1))) % mod;
            else
                res = (res + C(x, i) * T(x, y - i * (k + 1))) % mod;
        return (res + mod) % mod;
    };
    LL res = 0;
    if (m <= k)
        return C(n, m);
    int scope = std::min(k, m);
    for (int i = 0; i <= scope; i++)
        res = (res + R(n - m - 1, m - i) * (i + 1ll) % mod) % mod;
    return res;
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if (n == m)
        return puts(k != m ? "0" : "1"), 0;
    int res = PreWork();
    auto calc = [&](int x) -> LL
    { return S(n / x, m / x) * phi[x] % mod; };
    LL ans = 0;
    for (int i = 1; i * i <= res; i++)
        if (res % i == 0)
        {
            ans = (ans + calc(i)) % mod;
            if (i * i != res)
                ans = (ans + calc(res / i)) % mod;
        }
    printf("%lld\n", (ans * Invn % mod + mod) % mod);
    return 0;
}