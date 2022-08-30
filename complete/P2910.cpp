#include <bits/stdc++.h>
const int Maxn = 105, Maxm = 10010;
int d[Maxn][Maxn], a[Maxm];
int n, m, ans;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &d[i][j]);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 2; i <= m; i++)
        ans += d[a[i - 1]][a[i]];
    printf("%d\n", ans);
    return 0;
}