#include <bits/stdc++.h>
const int Maxn = 2010, mod = 1e9 + 9;
using LL = long long;
int n, k, a[Maxn], b[Maxn];
LL f[Maxn][Maxn], fac[Maxn], inv[Maxn], cnt[Maxn], ans;
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[j] < a[i]) cnt[i]++;
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    // std::cout << fac[2] << "\n";
    for (int i = 2; i <= n; i++)
        inv[i] = inv[i - 1] * inv[i] % mod;
}
LL C(int x, int y)
{
    if (x < y || x < 0 || y < 0) return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);
    init();
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= std::min((int)cnt[i], i); j++)
        {
            if (j == 0)
                f[i][0] = f[i - 1][0];
            else
                f[i][j] = (f[i - 1][j - 1] * (cnt[i] - j + 1) + f[i - 1][j]) % mod;
        }
    for (int j = 1; j <= n; j++)
    {
        f[n][j] = f[n][j] * fac[n - j] % mod;
        // std::cout << f[n][j] << " ";
    }
        
    k = (n + k) / 2;
    for (int i = k; i <= n; i++)
    {
        if ((i - k) & 1) ans = (ans - f[n][i] * C(i, k) % mod + mod) % mod;
        else ans = (ans + f[n][i] * C(i, k)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
 }