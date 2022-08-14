#include <bits/stdc++.h>
const int Maxn = 102, Maxm = 9, lim = 65;
int n, m, f[Maxn][lim][lim];
int cnt[lim], sta[lim], ban[Maxn], tot;
inline void init()
{
    for (int i = 0; i < (1 << m); i++)
    {
        if (i & (i << 1)) continue;
        if (i & (i << 2)) continue;
        int sav = 0;
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) sav++;
        cnt[++tot] = sav;
        sta[tot] = i;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            do{
                ch = getchar();
            }while (ch != 'H' && ch != 'P');
            ban[i] = (ban[i] << 1) + (ch == 'H');
        }
    init();
    auto check_dx = [](int raw, int id) {
        return (ban[raw] & sta[id]);
    };
    auto check_pb = [](int x, int y){
        return (sta[x] & sta[y]);
    };
    for (int i = 1; i <= tot; i++)
    {
        if (check_dx(1, i)) continue;
        f[1][i][0] = cnt[i];
    }
    if (n == 1)
    {
        int ans = 0;
        for (int i = 1; i <= tot; i++)
            ans = std::max(ans, cnt[i]);
        return printf("%d", ans), 0;
    }
    for (int i = 1; i <= tot; i++)
    {
        if (check_dx(2, i)) continue;
        for (int j = 1; j <= tot; j++)
        {
            if (check_dx(1, j) || check_pb(i, j)) continue;
            f[2][i][j] = std::max(f[2][i][j], f[1][j][0] + cnt[i]);
        }
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= tot; j++)
        {
            if (check_dx(i, j)) continue;
            for (int k = 1; k <= tot; k++)
            {
                if (check_pb(k, j) || check_dx(i - 1, k)) continue;
                for (int l = 1; l <= tot; l++)
                {
                    if (check_pb(k, l) || check_pb(j, l) || check_dx(i - 2, l))
                        continue;
                    f[i][j][k] = std::max(f[i][j][k], f[i - 1][k][l] + cnt[j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++)
            ans = std::max(ans, f[n][i][j]);
    printf("%d\n", ans);
    return 0;
}