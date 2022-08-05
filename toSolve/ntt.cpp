#include <bits/stdc++.h>
const int Maxn = 135000 + 5;
int f[Maxn << 1], g[Maxn << 1], tr[Maxn << 1];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 0; i <= n; i++)
        scanf("%d", &g[i]);
    n++, m++;
    return 0;
}