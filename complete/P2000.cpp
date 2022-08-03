#include <bits/stdc++.h>
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
using LL = long long;
const int N = 1e6 + 5, mod = 998244353, G = 3;
int lst, tr[N];
int f[4][N];
void print_array(int *f, int n)
{
    for (int i = n; i >= 0; i--)
        printf("%d", f[i]);
    printf("\n");
}
int qpow(LL x, LL y = mod - 2)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
    } return (int)res;
}
const int invG = qpow(G);
void merge(int *f, int *g, int n)
{
    for (int i = 0; i < n; i++)
        f[i] = (int)(1ll * f[i] * g[i] % mod);
}
void bfly(int n)
{
    if (lst == n) return;
    for (int i = 0; i < n; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
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
                int tt = (int)(buf * f[l + len] % mod);
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
void times(int *f, int *g, int n)
{
    ntt(f, 1, n), ntt(g, 1, n);
    merge(f, g, n);
    ntt(f, 0, n);
    for (int i = 0; i < n; i++)
        f[i + 1] += f[i] / 10, f[i] = f[i] % 10;
}
void plus(int *f, int x, int len)
{
    f[len] += x;
    f[len - 1] += f[len] / 10;
    f[len] = f[len] % 10;
}
void divi(int *f, int n, int x)
{
    int sav = 0;
    for (int i = n; i >= 0; i--)
    {
        // std::cout << f[i] << " ";
        sav = (sav % x) * 10 + f[i];
        f[i] = sav / x;
    }
}
int main()
{
    std::string s;
    std::cin >> s;
    int len = s.size() - 1;
    for (int i = 0; i <= len; i++)
        for (int j = 0; j <= 3; j++) f[j][i] = s[i] - '0';
    for (int i = 0; i <= 3; i++)
    {
        plus(f[i], i + 1, len);
        std::reverse(f[i], f[i] + len + 1);
    }
    int n = 1;
    len = std::max(len * 4, 8);
    for (;  n <= len; n <<= 1)
        continue;
    times(f[0], f[1], n);
    times(f[0], f[2], n);
    times(f[0], f[3], n);
    divi(f[0], n, 24);
    while (n && !f[0][n]) n--;
    print_array(f[0], n);
    return 0;
}
// (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24