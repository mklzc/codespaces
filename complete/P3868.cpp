#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
using LL = long long;
const int N = 15;
LL m[N], a[N], mul[N], n;
void exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
        return void(x = 1), void(y = 0);
    exgcd(b, a % b, x, y);
    LL z = x; x = y;
    y = z - y * (a / b);
}

LL crt()
{
    auto inv = [&](LL a, LL b) ->LL{
        LL x, y;
        exgcd(a, b, x, y);
        return (x % b + b) % b;
    };
    auto Mul = [](LL x, LL y, LL mod)->LL{
        LL res = 0;
        for (; y; y >>= 1) {
            if (y & 1) res = (res + x) % mod;
            x = (x + x) % mod;
        }return res;
    };
    LL M = 1, ans = 0;
    rep(i, 1, n) M = M * m[i];
    rep(i, 1, n)
    {
        mul[i] = M / m[i];
        LL x = inv(mul[i], m[i]);
        ans = (ans + Mul(Mul(a[i], mul[i], M), x, M)) % M;
    }
    return ans % M;
}
int main()
{
    fin;
    read(n);
    rep(i, 1, n) read(a[i]);
    rep(i, 1, n) read(m[i]);
    rep(i, 1, n) a[i] %= m[i];
    printf("%lld\n", crt());
	return 0;
}