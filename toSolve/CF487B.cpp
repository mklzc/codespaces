#include <bits/stdc++.h>
const int Maxn = 100010;
const int INF = 0x3f3f3f3f;
int n, s, L, a[Maxn];
int fx[Maxn << 1][19], fn[Maxn << 1][19];
int dp[Maxn];
void init()
{
    for (int i = 1; i <= n; i++)
        fx[i][0] = fn[i][0] = a[i];
    int k = std::log2(n) + 1;
    for (int j = 1; (1 << j - 1) <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            fx[i][j] = std::max(fx[i][j - 1], fx[i + (1 << j - 1)][j - 1]);
            fn[i][j] = std::min(fn[i][j - 1], fn[i + (1 << j - 1)][j - 1]);
        }
    }
}
int check(int l, int r)
{
    if (r - l + 1 > L) return false;
    int k = std::log2(r - l + 1);
    int mx = std::max(fx[l][k], fx[r - (1 << k) + 1][k]);
    int mn = std::min(fn[l][k], fn[r - (1 << k) + 1][k]);
    return (mx - mn) <= s;
}
int main()
{
    scanf("%d %d %d", &n, &s, &L);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    init();
    puts("yes");
    int pos = 0;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = L; i <= n; i++)
    {
        while (!check(pos + 1, i) || dp[pos] == INF) pos++;
        dp[i] = std::min(dp[i], dp[pos] + 1);
    }
    printf("%lld\n", dp[n]);
    return 0;
}