#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 35010, INF = 0x3f3f3f3f;
int n, a[Maxn], b[Maxn], f[Maxn], len[Maxn];
LL g[Maxn], costl[Maxn], costr[Maxn];
std::vector<int> ed[Maxn];
const bool IsPrint = false;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i] - i;
    for (int i = 1; i <= n; i++)
        if (IsPrint) printf("%d ", b[i]);
    if (IsPrint) printf("\n");
    int Maxl = 0;
    b[n + 1] = INF;
    for (int i = 1; i <= n + 1; i++)
    {
        int l = 0, r = Maxl, fpos = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f[mid] <= b[i])
                fpos = mid, l = mid + 1;
            else r = mid - 1;
        }
        Maxl += (fpos == Maxl);
        f[fpos + 1] = b[i];
        len[i] = fpos + 1;
        ed[len[i]].push_back(i);
        if (IsPrint)
            std::cout << len[i] << " " << i << "\n";
    }
    printf("%d\n", n - Maxl + 1);
    memset(g, 0x3f, sizeof(g));
    ed[0].push_back(0);
    g[0] = 0, b[0] = -INF;
    for (int i = 1; i <= n + 1; i++)
    {
        for (auto pre : ed[len[i] - 1])
        {
            if (pre > i || b[pre] > b[i]) continue;
            if (IsPrint) printf("pre=%d i=%d\n", pre, i);
            costl[pre] = costr[i] = 0;
            for (int l = pre + 1, r = i - 1; l <= i - 1 && r >= pre + 1; l++, r--)
            {
                costl[l] = costl[l - 1] + std::abs(b[l] - b[pre]);
                costr[r] = costr[r + 1] + std::abs(b[r] - b[i]);
            }
            for (int k = pre; k <= i - 1; k++)
            {
                if (IsPrint)
                    printf("cl[%d]=%lld cr[%d]=%lld g[pre]=%lld\n", k, costl[k], k, costr[k + 1], g[pre]);
                g[i] = std::min(g[i], g[pre] + costl[k] + costr[k + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (IsPrint) printf("%lld ", g[i]);
    if (IsPrint) printf("\n");

    printf("%lld\n", g[n + 1]);
    return 0;
}