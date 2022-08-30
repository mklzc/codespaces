#include <bits/stdc++.h>
using LL = int;
const int Maxn = 32769;
int n, T;
LL f[Maxn][4][182], a[185];
LL dfs(int i, int j, int k)
{
    // std::cout << i << " " << j << " " << k << "\n";
    if (i == 0) return 1;
    // if (i < 0) return 0;
    if (j == -1) return 0;
    if (k == 0) return 0;
    if (f[i][j][k] != -1) return f[i][j][k];
    LL res = 0;
    for (int d = 1; d <= k; d++)
    {
        if (a[d] * a[d] > i) break;
        res += dfs(i - a[d] * a[d], j - 1, d);
    }
    f[i][j][k] = res;
    return res;
}
int main()
{
    std::memset(f, -1, sizeof f);
    std::iota(a + 1, a + 183, 1);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", dfs(n, 3, 181));
    }
    return 0;
}