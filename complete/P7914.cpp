#include <bits/stdc++.h>
using LL = long long;
const int mod = 1000000007, Maxn = 505;
int n, k;
LL f[Maxn][Maxn][5];
char s[Maxn];
int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    auto add = [](LL x, LL y) ->LL{
        return (x + y) % mod;
    };
    for (int i = 1; i <= n; i++) 
    {
        f[i][i - 1][0] = 1;
        f[i][i][0] = (s[i] == '*' || s[i] == '?');
    }
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            if (len <= k) f[l][r][0] = f[l][r - 1][0] && (s[r] == '*' || s[r] == '?');
            if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?'))
                f[l][r][1] = (add(f[l + 1][r - 1][0], f[l + 1][r - 1][2]) + add(f[l + 1][r - 1][3], f[l + 1][r - 1][4])) % mod;
            for (int k = l; k <= r - 1; k++)
            {
                f[l][r][2] = (f[l][r][2] + f[l][k][4] * f[k + 1][r][0]) % mod;
                f[l][r][3] = (f[l][r][3] + f[l][k][0] * f[k + 1][r][4]) % mod;
                f[l][r][4] = (f[l][r][4] + add(f[l][k][4], f[l][k][2]) * f[k + 1][r][1]) % mod;
            }
            f[l][r][4] = add(f[l][r][4], f[l][r][1]);
        }
    }
    printf("%lld\n", f[1][n][4]);
    return 0;
}