#include <bits/stdc++.h>
const int N = 2050, mod = 998244353;
using LL = long long;
auto sign = [](int x)
    -> LL{ return (x & 1) ? -1 : 1; };
auto mul = [](LL a, LL b, LL c, LL d, LL e)
    -> LL{ return ((((a * b % mod) * c % mod) * d) % mod * e) % mod; };
LL inv[N], fac[N], D[N], pow2[N];
LL C(int x, int y) { return fac[x] * inv[y] % mod * inv[x - y] % mod; }
void init()
{
    fac[1] = inv[1] = fac[0] = inv[0] = pow2[0] = 1;
    pow2[1] = 2;
    for (int i = 2; i < N; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod,
        fac[i] = fac[i - 1] * i % mod,
        pow2[i] = (pow2[i - 1] << 1) % mod;
    for (int i = 2; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
    for (int n = 0; n < (N >> 1); n++)
        for (int i = 0; i <= n; i++)
            D[n] = (D[n] + sign(i) * mul(C(n, i), C(n, i), fac[i], pow2[i], fac[(n - i) << 1]) + mod) % mod;
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            printf("%lld\n", mul(C(n, i), C(n, i), fac[i], pow2[i], D[n - i]));
    }
    return 0;
}