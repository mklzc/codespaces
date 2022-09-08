#include <bits/stdc++.h>
using LL = long long;
template<typename T>
inline void read(T &x)
{
    x = 0; T w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    x = x * w;
}
const int Maxn = 1010;
int n, m, k, p, a[Maxn][Maxn];
LL row[Maxn], col[Maxn];
int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            read(a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            row[i] += a[i][j];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            col[j] += a[i][j];
    LL ans = 0;
    const int INF = 0x3f3f3f3f;
    for (int i = 1; i <= k; i++)
    {
        LL Max = -INF;
        int pos = 0, rc = -1;
        for (int j = 1; j <= n; j++)
            if (Max < row[j]) Max = row[j], pos = j, rc = 0;
        for (int j = 1; j <= m; j++)
            if (Max < col[j]) Max = col[j], pos = j, rc = 1;
        if (!rc)
        {
            row[pos] -= 1ll * m * p;
            for (int j = 1; j <= m; j++) col[j] -= p;
        }
        else
        {
            col[pos] -= 1ll * n * p;
            for (int j = 1; j <= n; j++) row[j] -= p;
        }
        ans += Max;
    }
    printf("%d\n", ans);
    return 0;
}