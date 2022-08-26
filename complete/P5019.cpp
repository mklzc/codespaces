#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
int n, d[Maxn], b[Maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
        b[i] = d[i] - d[i - 1];
    }
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < 0) res1 += std::abs(b[i]);
        else res2 += std::abs(b[i]);
    }
    printf("%d\n", std::max(res1, res2));
    return 0;
}