#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x)
{
    x = 0;
    T w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    x = x * w;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args)
{
    read(x);
    read(args...);
}
typedef long long LL;
const int N = 5e5 + 5, mod = 1e9 + 7;
int n;
LL a[N], b[N];

inline LL qpow(LL x, LL y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
    }
    return res;
}
inline int raw()
{
    read(n);
    LL M = 1, Smod = 1, S = 1;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        M = (M * a[i]) % mod;
    }
    for (int i = 1; i <= n; i++)
        read(b[i]);
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
        {
            Smod = (Smod + b[i]) % mod;
            S += b[i];
        }
    LL pos = 0, ans = 0;
    bool tag = true, st = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            continue;
        st = true;
        if (tag == true || (S + b[i]) * a[pos] > (S + b[pos]) * a[i])
        {
            LL sum = (S + b[i]) % mod;
            LL mul = M * qpow(a[i], mod - 2) % mod;
            ans = (sum * mul) % mod;
            pos = i;
            tag = false;
        }
    }
    if (!st)
        return printf("%lld\n", Smod), 0;
    if (S * a[pos] < S + b[pos])
        printf("%lld\n", ans);
    else
        printf("%lld\n", (Smod * M) % mod);
    return 0;
}
int main() { return raw(); }