#include <bits/stdc++.h>
const int Maxk = 1e7 + 5, mod = 998244353;
int n, m, p, k;
int ifac[Maxk], fac[Maxk], R[Maxk];
int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y = mod - 2)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    } return res;
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    R[k] = 1, p = qpow(m);
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= k; i++)
        ifac[i] = mul((mod - mod / i), ifac[mod % i]),
        fac[i] = mul(fac[i - 1], i);
    for (int i = 2; i <= k; i++)
        ifac[i] = mul(ifac[i - 1], i);
    for (int i = k - 1; i >= 1; i--)
    {
        R[i] = mul(1 - p, R[i + 1]);
    }
    return 0;
}