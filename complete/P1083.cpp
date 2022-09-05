#include <bits/stdc++.h>
const int Maxn = 1e6 + 5;
int n, m, lim[Maxn];
struct Didan {
    int d, s, t;
} didan[Maxn];
long long cnt[Maxn];
bool check(int x)
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= x; i++)
        cnt[didan[i].s] += didan[i].d,
        cnt[didan[i].t + 1] -= didan[i].d;
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; i++)
        if (cnt[i] > lim[i]) return false;
    return true;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &lim[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &didan[i].d, &didan[i].s, &didan[i].t);
    int l = 1, r = m, ans = m + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (!check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (ans != m + 1) printf("-1\n%d\n", ans);
    else printf("0");
    return 0;
}