#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 2e5 + 5;
const LL scp = 0x3f3f3f3f3f3f3f3f;
int n, m;
LL s, val[Maxn], cnt[Maxn];
struct KS {
    int w, v;
} t[Maxn];
struct interval {
    int l, r;
} q[Maxn];
LL check(LL x)
{
    memset(cnt, 0, sizeof(cnt));
    memset(val, 0, sizeof(val));
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1], val[i] = val[i - 1];
        if (t[i].w >= x) cnt[i]++, val[i] += t[i].v;
    }
    LL ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (val[q[i].r] - val[q[i].l - 1]) * (cnt[q[i].r] - cnt[q[i].l - 1]);
    return ans;
}
int main()
{
    scanf("%d %d %lld", &n, &m, &s);
    int Max = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &t[i].w, &t[i].v),
        Max = std::max(Max, t[i].w);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &q[i].l, &q[i].r);
    LL l = 1, r = Max, ans = 0;
    while (l <= r)
    {
        LL mid = (l + r) >> 1;
        LL res = check(mid);
        if (res >= s) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", std::min(check(ans) - s, s - check(ans + 1)));
    return 0;
}