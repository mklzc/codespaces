#include <bits/stdc++.h>
const int Maxn = 1350001, mod = 998244353, G = 3;
using LL = long long;
int tr[Maxn << 1], F1[Maxn << 1], F2[Maxn << 1];
void print(int *f, int n)
{
    for (int i = 0; i <= n; i++)
        printf("%d ", f[i]);
    printf("\n");
}
int qpow(int x, int y = mod - 2)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = (int)(1ll * res * x % mod);
        x = (int)(1ll * x * x % mod);
    }return res;
}
const int invG = qpow(G);
void bfly(int n)
{
    static int lst;
    if (lst == n) return;
    lst = n;
    for (int i = 0; i < n; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
void merge(int *f, int *g, int n)
{
    for (int i = 0; i < n; i++)
        f[i] = (int)(1ll * f[i] * g[i] % mod);
}
void ntt(int *f, bool si, int n)
{
    bfly(n);
    for (int i = 0; i < n; i++)
        if (i < tr[i]) std::swap(f[i], f[tr[i]]);
    for (int p = 2; p <= n; p <<= 1)
    {
        int len = p >> 1, e = qpow(si ? G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p)
        {
            LL buf = 1;
            for (int l = k; l < k + len; l++)
            {
                int tt = (int)(f[l + len] * buf % mod);
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
        f[i] = (int)(1ll * f[i] * invn % mod);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%d", &F1[i]);
    for (int i = 0; i <= m; i++)
        scanf("%d", &F2[i]);
    n++, m++;
    for (m += n, n = 1; n <= m; n <<= 1);
    ntt(F1, 1, n);
    ntt(F2, 1, n);
    merge(F1, F2, n);
    ntt(F1, 0, n);
    print(F1, m - 2);
    return 0;
}