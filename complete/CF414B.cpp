#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 2010, mod = 1e9 + 7;
int n, k;
LL f[Maxn][Maxn];
int cnt = 0, fac[Maxn];
void split(int x)
{
    cnt = 0;
    fac[++cnt] = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            fac[++cnt] = i;
            if (i * i != x) fac[++cnt] = x / i;
        }
    }
    if (x != 1) fac[++cnt] = x;
}
int main()
{
    scanf("%d %d", &n, &k);
    f[0][1] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            split(j);
            for (int d = 1; d <= cnt; d++)
                f[i][j] = (f[i][j] + f[i - 1][fac[d]]) % mod;
        }
    }
    LL ans = 0;
    // std::cout << f[1][3] << "\n";
    for (int i = 1; i <= n; i++)
        ans = (ans + f[k][i]) % mod;
    printf("%lld\n", ans);
    return 0;
}