#include <bits/stdc++.h>
const int Maxn = 105, mod = 1e6 + 7;
int n, m, f[Maxn], a[Maxn];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int k = std::min(j, a[i]); k >= 1; k--)
                f[j] = (f[j] + f[j - k]) % mod;
    printf("%d\n", f[m]);
    return 0;
}