#include <bits/stdc++.h>
const int Maxn = 35, Maxv = 2e4 + 5;
int a[Maxn], f[Maxv], n, V;
int main()
{
    scanf("%d", &V);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= a[i]; j--)
            f[j] = std::max(f[j - a[i]] + a[i], f[j]);
    printf("%d\n", V - f[V]);
    return 0;
}