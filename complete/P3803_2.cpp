#include <bits/stdc++.h>
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
#define ok std::cout << "ok\n"
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
using LL = long long;
const int N = 2700000, mod = 998244353, G = 3;
int n, m, tr[N], lst, f[N], g[N];
int qpow(LL x, LL y = mod - 2)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
    } return (int)res;
}
const LL invG = qpow(G);
void print_array(int *f, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", f[i]);
    printf("\n");
}
void bfly(int n)
{
    if (lst == n) return;
    lst = n;
    for (int i = 0; i < n; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
void merge(int *f, int *g, int n)
{
    for (int i = 0; i < n; ++i)
        f[i] = 1ll * f[i] * g[i] % mod;
}
void ntt(int *f, bool si, int n)
{
    bfly(n);
    for (int  i = 0; i < n; i++)
        if (i < tr[i]) std::swap(f[i], f[tr[i]]);
    
    for (int p = 2; p <= n; p <<= 1)
    {
        int len = p >> 1;
        int e = qpow(si ? G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p)
        {
            LL buf = 1;
            for (int l = k; l < k + len; l++)
            {
                int tt = buf * f[len + l] % mod;
                f[l + len] = f[l] - tt;
                if (f[l + len] < 0) f[l + len] += mod;
                f[l] = f[l] + tt;
                if (f[l] > mod) f[l] -= mod;
                buf = buf * e % mod;
            }
        }
    }
    if (si) return;
    int invn = qpow(n);
    for (int i = 0; i < n; i++)
        f[i] = 1ll * f[i] * invn % mod;
}
int main()
{
    scanf("%d %d", &n, &m);
    rep(i, 0, n)
        scanf("%d", &f[i]);
    rep(i, 0, m)
        scanf("%d", &g[i]); 
    n++, m++;
    for (m += n, n = 1; n < m; n <<= 1) continue;
    rep(i, 0, n - 1)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
    ntt(f, 1, n), ntt(g, 1, n);
    merge(f, g, n);
    ntt(f, 0, n);
    rep(i, 0, m - 2)
        printf("%d ", f[i]);
    return 0;
}