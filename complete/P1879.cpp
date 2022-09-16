#include <bits/stdc++.h>
const int Maxn = 13, mod = 1e9;
int n, m, a[Maxn], legal[1 << Maxn], tot;
int f[2][Maxn];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1, c; j <= n; j++)
        {
            scanf("%d", &c);
            a[i] = a[i] & (1 << c);
        }
            
    for (int sta = 0; sta < (1 << (Maxn - 1)); sta++)
    {
        if ((sta >> 1) & 1) continue;
        legal[++tot] = sta;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= tot; j++)
        {
            int now = legal[k];
            bool flag = false;
            for (int k = 0; k < n; k++)
                if (((now >> k) & 1) && !a[i][k]) { flag = true; break; }
            if (flag) continue;
            flag = false;
            for (int k = 1; k <= tot; k++)
            {
                int pre = legal[k];
                for (int p = 1; p <= n; p++)
                {
                    if (((pre >> p) & 1) && !a[i - 1][p]) {flag = true; break;}
                    if (flag) break;
                    f[]
                }
            }
        }
    }
    return 0;
}