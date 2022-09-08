#include <bits/stdc++.h>
const int Maxn = 2e3 + 5, mod = 998244353;
using LL = long long;
int n, k;
struct sav {
    int x, y;
} t[Maxn];
int inv(int x, int y = mod - 2)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
    }
    return res;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &t[i].x, &t[i].y);
    auto mul = [](int x, int y) ->int{
        return 1ll * x * y % mod;
    };
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int fi = 1;
        for (int j = 1; j <= n; j++)
            if (j != i) fi = mul(mul(fi, k - t[j].x), inv(t[i].x - t[j].x));
        ans = (ans + mul(fi, t[i].y)) % mod;
    }
    printf("%lld\n", (ans % mod + mod) % mod);
    return 0;
}