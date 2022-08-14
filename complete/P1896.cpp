#include <bits/stdc++.h>
const int Maxn = 12;
using LL = long long;
int n, k, tot, cnt[1 << Maxn], state[1 << Maxn];
LL f[Maxn][1 << Maxn][Maxn * Maxn];

void init()
{
    for (int i = 0; i < (1 << n); i++)
    {
        if (i & (i << 1)) continue;
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) ++sum;
        state[++tot] = i, cnt[tot] = sum;
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    init(); 
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int cur = 1; cur <= tot; cur++)
        {
            for (int l = cnt[cur]; l <= k; ++l)
            {
                for (int lst = 1; lst <= tot; lst++)
                {
                    if (state[cur] & state[lst]) continue;
                    if (state[cur] & (state[lst] << 1)) continue;
                    if ((state[cur] << 1) & state[lst]) continue;
                    f[i][state[cur]][l] += f[i - 1][state[lst]][l - cnt[cur]];
                }
            }
        }
    LL ans = 0;
    for (int i = 1; i <= tot; i++)
        ans += f[n][state[i]][k];
    printf("%lld\n", ans);
    return 0;
}