#include <bits/stdc++.h>
int n, m;
const int mod = 1e9 + 7;
using LL = long long;
LL qpow(int x, int y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = 1ll * x * x % mod;
    } return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    LL ans = 0;
    for (int i = 0; i <= n - 1; i++)
        ans = (ans + qpow(2 * m - 1, i) * qpow(m, n - i)) % mod;
    printf("%lld\n", (ans + qpow(m, n)) % mod);
    return 0;
}