#include <bits/stdc++.h>
const int Maxn = 1010;
std::bitset<Maxn> f[Maxn];
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, x, y; i <= m; i++)
        scanf("%d %d", &x, &y), f[x][y] = 1;
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (f[i][k]) f[i] = f[i] | f[k];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!f[i][j] && !f[j][i]) ans++, f[i][j] = f[j][i] = 1;
    printf("%d\n", ans);
    return 0;
}