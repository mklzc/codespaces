#include <bits/stdc++.h>
const int Maxn = 1e6 + 5, SUB = 1e5 + 5;
using LL = long long;
int n, C, a[Maxn];
LL sum[Maxn];
std::vector<int> val;
LL f[1005][1005], g[SUB][205];
bool sub3()
{
    if (C != 0) return false;
    printf("0\n");
    return true;
}
LL calc(int x) {return 1ll * a[x] * x - sum[x];}
bool sub4()
{
    for (int i = 2; i <= n; i++)
        if (a[i] <= a[i - 1]) return false;
    LL ans = LONG_LONG_MAX;
    for (int i = 0; i <= n; i++)
        ans = std::min(ans, 1ll * (n - i) * C + calc(i));
    printf("%lld\n", ans);
    return true;
}
void work1()
{
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < val.size(); x++)
        {
            f[i][x] = LONG_LONG_MAX;
            for (int y = 0; y < val.size(); y++)
            {
                if (x > y) continue;
                f[i][x] = std::min(f[i][x], f[i - 1][y] + (val[x] < a[i] ? C : val[x] - a[i]));
            }
        }
    }
    LL ans = LONG_LONG_MAX;
    for (int i = 0; i < val.size(); i++)
        ans = std::min(ans, f[n][i]);
    printf("%lld\n", ans);
}
void work2()
{
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < val.size(); x++)
        {
            g[i][x] = LONG_LONG_MAX;
            for (int y = 0; y < val.size(); y++)
            {
                if (x > y) continue;
                g[i][x] = std::min(g[i][x], g[i - 1][y] + (val[x] < a[i] ? C : val[x] - a[i]));
            }
        }
    }
    LL ans = LONG_LONG_MAX;
    for (int i = 0; i < val.size(); i++)
        ans = std::min(ans, g[n][i]);
    printf("%lld\n", ans);
}
int main()
{
    scanf("%d %d", &n, &C);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]),
        sum[i] = sum[i - 1] + a[i],
        val.push_back(a[i]);
    if (sub3()) return 0;
    else if(sub4()) return 0;
    if (n <= 1000) return work1(), 0;
    work2();
    return 0;
}