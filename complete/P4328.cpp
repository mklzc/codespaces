#include <bits/stdc++.h>
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
using LL = long long;
using  ull = unsigned long long;
const int _G = 3, mod = 998244353, Maxn = 1000005;
int lst, tr[Maxn], F[Maxn];
inline int qpow(LL x, LL y = mod - 2)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
    } return (int)res;
}
inline void print_array(int *f, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", f[i]);
    printf("\n");
}
const int invG = (int)qpow(_G);
inline void bfly(int n)
{
    if (lst == n) return;
    lst = n;
    for (int i = 0; i < n; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
inline void merge(int *f, int *g, int n)
{
    for (int i = 0; i < n; ++i)
        f[i] = (int)(1ll * f[i] * g[i] % mod);
}
inline void NTT(int *f, bool si, int n)
{
    bfly(n);
    for (int  i = 0; i < n; i++)
        if (i < tr[i]) std::swap(f[i], f[tr[i]]);
    for (int p = 2; p <= n; p <<= 1)
    {
        int len = p >> 1;
        int e = qpow(si ? _G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p)
        {
            LL buf = 1;
            for (int l = k; l < k + len; l++)
            {
                int tt = (int)(buf * f[len + l] % mod);
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

inline void invf(int *f, int m)
{
    int n = 1;
    for (; n < m; n <<= 1)
        continue;
    static int  w[Maxn << 1], r[Maxn << 1], sav[Maxn << 1];
    w[0] = qpow(f[0]);
    for (int p = 2; p <= n; p <<= 1)
    {
        for (int i = 0; i < (p >> 1); i++)
            r[i] = (w[i] << 1) % mod;
        cpy(sav, f, p);
        NTT(w, 1, p << 1);
        NTT(sav, 1, p << 1);
        merge(w, w, p << 1);
        merge(w, sav, p << 1);
        
        NTT(w, 0, p << 1);
        clr(w + p, p);
        for (int i = 0; i < p; i++)
            w[i] = (r[i] - w[i] + mod) % mod;
    }
    cpy(f, w, m);
    clr(w, n << 1), clr(sav, n << 1), clr(r, n << 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &F[i]);
    invf(F, n);
    print_array(F, n);
    return 0;
}