#include <bits/stdc++.h>
const int Maxn = 100010;
int n, c, d[Maxn];
bool check(int x)
{
    int cnt = c - 1, j = 0, sum = 0;
    for (int i = 2; i <= n; i = j)
    {
        j = i + 1, sum = d[i];
        while (sum < x && j <= n)
            sum += d[j], j++;
        if (sum >= x) cnt--;
    }
    return (cnt <= 0);
}
int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    std::sort(d + 1, d + n + 1);
    int l = 1, r = d[n] - d[1], ans = d[n] - d[1];
    for (int i = n; i >= 0; i--)
        d[i] = d[i] - d[i - 1];
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}