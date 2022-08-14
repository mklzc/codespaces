#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
double a[Maxn], b[Maxn], f[Maxn], p[Maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);
    a[1] = b[1] = f[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] + 1) * p[i];
        b[i] = (b[i - 1] + 2 * a[i - 1] + 1) * p[i];
        f[i] = f[i - 1] + (3 * b[i - 1] + 3 * a[i - 1] + 1) * p[i];
    }
    printf("%.1lf", f[n]);
    return 0;
}