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
const int N = 15;
int m[N], a[N], n;
long long mul[N];
void exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
        return void(x = 0), void(y = 1);
    exgcd(b, a % b, x, y);
    int z = x; x = y;
    y = z - y * (a / b);
}
long long crt()
{
    auto inv = [&](long long a, long long b) ->long long{
        int x, y;
        exgcd(a, b, x, y);
        return (x % b + b) % b;
    };
    long long M = 1, ans = 0;
    rep(i, 1, n) M = M * m[i];
    rep(i, 1, n)
    {
        mul[i] = M / m[i];
        int x = inv(mul[i], m[i]);
        ans = (ans + a[i] * mul[i] * x) % M;
    }
    return ans % M;
}
int main()
{
    read(n);
    rep(i, 1, n) read(a[i]);
    rep(i, 1, n) read(m[i]);
    printf("%lld\n", crt);
	return 0;
}