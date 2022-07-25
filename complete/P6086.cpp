// url: https://www.luogu.com.cn/problem/P6086
#include <bits/stdc++.h>
#define rep(VAR, st, ed) for(int VAR = st; VAR <= ed; VAR++)
int n, m;
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
const int N = 5e6 + 5;
int fa[N], prufer[N], dag[N];
void ttp()
{
    rep(i, 1, n - 1)
        read(fa[i]), ++dag[fa[i]];
    int p = 1;
    rep(i, 1, n - 2)
    {
        while (dag[p]) p++;
        prufer[i] = fa[p];
        while (i <= n - 2 && !(--dag[prufer[i]]) && prufer[i] < p)
            prufer[i + 1] = fa[prufer[i]], i++;
        p++;
    }
    long long ans = 0;
    rep(i, 1, n - 2)
        ans ^= 1ll * i * prufer[i];
    printf("%lld\n", ans);
}
void ptt()
{
    rep(i, 1, n - 2)
        read(prufer[i]), dag[prufer[i]]++;
    prufer[n - 1] = n;
    int p = 1;
    rep(i, 1, n - 1)
    {
        while (dag[p]) p++;
        fa[p] = prufer[i];
        while (i <= n - 1 && !(--dag[prufer[i]]) && prufer[i] < p)
            fa[prufer[i]] = prufer[i + 1], i++;
        p++;
    }
    long long ans = 0;
    rep(i, 1, n - 1)
        ans ^= 1ll * i * fa[i];
    printf("%lld\n", ans);
}
int main()
{
    scanf("%d %d", &n, &m);
    if (m == 1) ttp();
    else ptt();
    return 0;
}