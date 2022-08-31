#include <bits/stdc++.h>
const int Maxn = 5e4 + 2;
int L, n, m, d[Maxn];
bool check(int x)
{
}
int main()
{
    scanf("%d %d %d", &L, &n, &m);
    int Max = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]),
        Max = std::max(Max, d[i] - d[i - 1]);
    int l = 1, r = Max, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}