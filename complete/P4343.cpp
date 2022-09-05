#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 1e5 + 5;
int L, k, timer[Maxn];
int check(LL x)
{
    int cnt = 0;
    long long sum = 0;
    for (int i = 1; i <= L; i++)
    {
        sum += timer[i];
        if (sum < 0) sum = 0;
        if (sum >= x) cnt++, sum = 0;
    }
    return cnt;
}
int main()
{
    scanf("%d %d", &L, &k);
    for (int i = 1; i <= L; i++)
        scanf("%d", &timer[i]);
    const LL scp = 1e18;
    LL l = 1, r = scp, Max = scp + 1, Min = scp + 1;
    while (l <= r)
    {
        LL mid = (l + r) >> 1;
        int res = check(mid);
        if (res >= k)
        {
            l = mid + 1;
            if (res == k) Max = mid;
        }
        else r = mid - 1;
    }
    l = 1, r = scp;
    while (l <= r)
    {
        LL mid = (l + r) >> 1;
        int res = check(mid);
        if (res <= k)
        {
            r = mid - 1;
            if (res == k) Min = mid;
        }
        else l = mid + 1;
    }
    if (Max == scp + 1 || Min == scp + 1) printf("-1");
    else printf("%lld %lld\n", Min, Max);
    return 0;
}