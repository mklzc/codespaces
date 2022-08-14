#include <bits/stdc++.h>
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
};
using IO::read;
using LL = long long;
inline LL randint(LL l, LL r)
{
    static std::mt19937_64 eng(std::random_device{}());
    static std::uniform_int_distribution<LL> dis(l, r);
    return dis(eng);
}
inline LL gcd(LL a, LL b)
{
    if (!a) return b;
    LL t = b;
    while ((b = t))
        t = a % b, a = b;
    return a;
}
inline LL mul(LL a, LL b, LL m)
{
    LL r = ((long double)a / m * b + 0.5);
    r = a * b - r * m;
    return r < 0 ? r + m : r;
}
inline LL qpow(LL x, LL y, LL p)
{
    LL ans = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            ans = mul(ans, x, p);
        x = mul(x, x, p);
    }
    return ans;
}
bool mr(LL n, LL a)
{
    LL t = n - 1;
    while (t)
    {
        LL buf = qpow(a, t, n);
        if (buf != 1 && buf != n - 1)
            return false;
        if ((t & 1) || buf == n - 1)
            return true;
        t >>= 1;
    }
    return true;
}
bool is_prime(LL n)
{
    static const int tlist[] = {2, 3, 5, 7, 13, 19, 61, 233};
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 19 || n == 61 || n == 233) return true;
    for (int i = 0; i < 8; i++)
        if (!mr(n, tlist[i])) return false;
    return true;
}

LL prho(LL n, LL c)
{
    int lim = 1, tot = 0;
    static LL sav[150];
    auto f = [&](LL x) ->LL{
        if (!x) return c;
        return (mul(x, x, n) + c) % n;
    };
    LL x1 = f(0), x2 = f(f(0)), buf;
    while (true)
    {
        buf = mul(x1 - x2 + n, buf, n);
        sav[++tot] = x1 - x2 + n;
        if (tot == lim)
        {
            if (gcd(buf, n) > 1) break;
            tot = 0;
            lim = std::min(lim << 1, 128);
        }
        x1 = f(x1), x2 = f(f(x2));
    }
    for (int i = 1; i <= tot; i++)
    {
        buf = gcd(sav[i], n);
        if (buf > 1) return buf;
    }

    return n;
}
LL ans;
void solve(LL n)
{
    if (n <= ans) return;
    if (n == 4) {
        ans = std::max(ans, 2LL);
        return;
    }
    if (is_prime(n))
    {
        ans = std::max(ans, n);
        return;
    }
    LL sav = prho(n, randint(3, n - 1));
    while (sav == n)
        sav = prho(n, randint(3, n - 1));
    solve(sav);
    solve(n / sav);
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int T;
    read(T);
    while (T--)
    {
        ans = 0;
        LL a;
        read(a);
        if (is_prime(a))
        {
            puts("Prime");
            // std::cerr << "Prime\n";
            continue;
        }
        solve(a);   
        printf("%lld\n", ans);
        // std::cerr << ans << "\n";
    }
    return 0;
}