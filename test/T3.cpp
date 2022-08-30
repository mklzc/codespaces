#include <bits/stdc++.h>
#define int long long
const int Maxn = 1e5 + 5;
using LL = long long;
int n;
LL a, b, v[Maxn], Max[Maxn];
LL f(LL x, int scp)
{
    LL ans = 0;
    for (int i = 1; i <= scp; i++)
    {
        if (v[i] < x) ans += a * (x - v[i]);
        else ans += b * (v[i] - x);
    }
    return ans;
}
LL SanFen(LL l, LL r, int scp)
{
    while (l < r)
    {
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if (f(lmid, scp) > f(rmid, scp)) l = lmid + 1;
        else r = rmid - 1;
    }
    return f(l, scp) > f(r, scp) ? l : r;
}
int main()
{
    scanf("%d %lld %lld", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &v[i]), Max[i] = std::max(Max[i - 1], v[i]);
    for (int i = 1; i <= n; i++)
        printf("%lld\n", f(SanFen(1, Max[i], i), i));
    return 0;
}
