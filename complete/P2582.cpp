#include <bits/stdc++.h>
const int Maxn = 8e5 + 5;
int n, f[Maxn], g[Maxn], sz[Maxn], num[Maxn];
bool vis[Maxn];
void print_array(int *f, int len)
{
    for (int i = 1; i <= len; i++)
        std::cout << f[i] << " "; 
    std::cout << std::endl; 
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        int x = i, cnt = 0;
        do {x = f[x], ++cnt;} while(x != i);
        do {x = f[x]; sz[x] = cnt; vis[x] = true;} while(x != i);
        if (!num[cnt]) num[cnt] = x;
    }
    // print_array(sz, n);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        int sav = 0x3f3f3f3f;
        for (int j = 1; j * j <= sz[i]; j++)
        {
            if (sz[i] % j == 0)
            {
                if (num[j]) sav = std::min(sav, num[j]);
                if (j * j != sz[i] && num[sz[i] / j])
                    sav = std::min(sav, num[sz[i] / j]);
            }
        }
        int x = i;
        do {g[x] = sav, vis[x] = true, x = f[x], sav = f[sav]; } while(x != i);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", g[i]);
    return 0;
}