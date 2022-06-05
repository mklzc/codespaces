// url: https://www.luogu.com.cn/problem/P5091
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL phi, a, b, mod, ans;
template <typename T>
inline bool read(T &x)
{
    bool st = 0;
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x * 10) + ch - 48;
        if (x >= phi) st = 1, x %= phi;
        ch = getchar();
    }
    return st == 1;
}
LL PHI(int x)
{
    LL res = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            res = (res * (i - 1) / i) % mod;
            while (x % i == 0)
                x = x / i;
        }
    if (x > 1)
        res = (res * (x - 1) / x) % mod;
    return res;
}
LL qpow(LL x, LL y)
{
    LL res = 1 % mod;
    for (; y; y >>= 1) {
        if (y & 1) res = (res * x) % mod;
        x = x * x % mod;
    }
    return res;
}
LL raw()
{
    scanf("%lld %lld", &a, &mod);
    phi = PHI(mod);
    bool st = read(b);
    b = st ? b % phi + phi : b;
    return qpow(a, b);
}
int main() { return printf("%lld\n", raw()), 0; }