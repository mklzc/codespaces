// url: https://www.luogu.com.cn/problem/P4931
#include <bits/stdc++.h>
const int N = 5e6 + 10, mod = 998244353;
using LL = long long;
LL inv[N], fac[N], D[N], pow2[N];
LL mul(LL a, LL b, LL c, LL d, LL e) { return ((((a * b % mod) * c % mod) * d) % mod * e) % mod; }
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
    D[0] = 1, D[1] = 0, D[2] = 16;
    for (int i = 2; i < N - 2; i++)
        D[i + 1] = (mul(4, i, i + 1, D[i], 1) + mul(8, i, i, i + 1, D[i - 1])) % mod;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, i;
        scanf("%d %d", &n, &i);
        long long ans = mul(C(n, i), C(n, i), fac[i], pow2[i], D[n - i]);
        printf("%lld\n", ans);
    }
    return 0;
}