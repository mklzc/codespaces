#include <bits/stdc++.h>
const int Maxn = 350, MaxCnt = 45;
int n, m, a[Maxn], b[Maxn];
int f[MaxCnt][MaxCnt][MaxCnt][MaxCnt], cnt[5];
int dist(int d1, int d2, int d3, int d4) { return d1 + d2 * 2 + d3 * 3 + d4 * 4; }
struct sav { int d1, d2, d3, d4; };
std::vector<sav> q;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]), cnt[b[i]]++;
    for (int i = 0; i <= cnt[1]; i++)
    {
        for (int j = 0; j <= cnt[2]; j++)
        {
            for (int k = 0; k <= cnt[3]; k++)
            {
                for (int l = 0; l <= cnt[4]; l++)
                {
                    int dis = dist(i, j, k, l) + 1;
                    if (dis > n) continue;
                    if (dis == n) q.push_back((sav){i, j, k, l});
                    int res1 = std::max(f[(i - 1 >= 0) ? i - 1 : 0][j][k][l], f[i][(j - 1 >= 0) ? j - 1 : 0][k][l]);
                    int res2 = std::max(f[i][j][(k - 1 >= 0) ? k - 1 : 0][l], f[i][j][k][(l - 1 >= 0) ? l - 1 : 0]);
                    f[i][j][k][l] = std::max(res1, res2) + a[dis];
                }
            }
        }
    }
    int ans = 0;
    for (auto x : q)
        ans = std::max(ans, f[x.d1][x.d2][x.d3][x.d4]);
    printf("%d\n", ans);
    return 0;
}