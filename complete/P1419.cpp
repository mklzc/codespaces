#include <bits/stdc++.h>
const int Maxn = 2e5 + 100;
const double eps = 1e-6, inf = 0x3f3f3f3f;
int n, s, t, a[Maxn];
double b[Maxn], sum[Maxn];
int q[Maxn];
bool check(double x)
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + 1.0 * a[i] - x;
    int l = 1, r = 0, len = t - s + 1;
    for (int i = 1; i <= n + t; i++)
    {
        while (l <= r && i - q[l] + 1 > len) l++;
        while (l <= r && sum[q[r]] <= sum[i]) r--;
        q[++r] = i;
        b[i] = sum[q[l]];
    }
    double res = -inf;
    for (int i = 0; i <= n; i++)
        res = std::max(res, b[i + t] - sum[i]);
    return (res >= 0);
}
int main()
{
    scanf("%d", &n);
    scanf("%d %d", &s, &t); 
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    double l = -1e4, r = 1e4, mid;
    for (int i = 1; i <= t; ++i) sum[i + n] = -inf;
    while (r - l > eps)
    {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.3lf\n", mid);
    return 0;
}