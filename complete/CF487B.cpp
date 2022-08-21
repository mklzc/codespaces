#include <bits/stdc++.h>
const int Maxn = 100010, INF = 0x3f3f3f3f;
int n, s, L, a[Maxn];
int fx[Maxn << 1][19], fn[Maxn << 1][19], dp[Maxn];
void init()
{
    for (int i = 1; i <= n; i++)
        fx[i][0] = fn[i][0] = a[i];
    int k = std::log2(n) + 1;
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n; i++)
        {
            fx[i][j] = std::max(fx[i][j - 1], fx[i + (1 << j - 1)][j - 1]);
            fn[i][j] = std::min(fn[i][j - 1], fn[i + (1 << j - 1)][j - 1]);
        }
}
int check(int l, int r)
{
    int k = std::log2(r - l + 1);
    int Mn = std::min(fn[l][k], fn[r - (1 << k) + 1][k]);
    int Mx = std::max(fx[l][k], fx[r - (1 << k) + 1][k]);
    if (Mx - Mn > s) return false;
    return true;
}
int main()
{
    scanf("%d %d %d", &n, &s, &L);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    init();
    for (int i = 1; i <= n; i++) dp[i] = INF;
    for (int i = L, pos = 0; i <= n; i++)
    {
        while (i - pos + 1 > L && (dp[pos] == INF || !check(pos + 1, i)))
            pos++;
        if (i - pos + 1 > L && dp[pos] != INF)
            dp[i] = std::min(dp[pos] + 1, dp[i]);
    }
    printf("%d\n", dp[n] != INF ? dp[n] : -1);
    return 0;
}