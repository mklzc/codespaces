#include <bits/stdc++.h>
using LL = long long;
using PLI = std::pair<LL, int>;
std::mt19937 eng(std::random_device{}());
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL mul(LL a, LL b, LL m)
{
    return (__int128_t) a * b % m;
}
LL qpow(LL a ,LL b, LL m)
{
    LL res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1) res = mul(res, a, m);
        a = mul(a, a, m);
    }
    return res;
}
bool mr(LL n, LL a)
{
    LL t = n - 1;
    while (t)
    {
        LL buf = qpow(a, t, n);
        if (buf != 1 && buf != n - 1) return false;
        if ((t & 1) || buf == n - 1) return true;
        t >>= 1;
    }
    return true;
}
bool is_prime(LL n)
{
    if (n < 2) return false;
    static const int tl[] = {2, 3, 5, 7, 11, 13, 61, 233};
    for (int i = 0; i < 8; i++)
        if (n == tl[i]) return true;
    for (int i = 0; i < 8; i++)
        if (!mr(n, tl[i])) return false;
    return true;
}
LL phro(LL n, LL c)
{
    static int cnt = 0;
    int lim = 1, tot = 0;
    auto f = [&](LL x) ->LL{
        if (!x) return c;
        return (mul(x, x, n) + c) % n;
    };
    std::uniform_int_distribution<LL> dis(3, n - 1);
    LL x1 = f(dis(eng)), x2 = f(x1), buf = 1;
    while (true)
    {
        buf = mul(std::abs(x1 - x2), buf, n);
        if (!buf) return n;
        if ((++ tot) == lim)
        {
            if (gcd(buf, n) > 1) return gcd(buf, n);
            tot = 0, buf = 1;
            lim = std::min(lim << 1, 128);
        }
        x1 = f(x1), x2 = f(f(x2));
    }
    return n;
}
LL p, m, n;
bool flag = false;
std::vector<LL> tmpfac;
std::vector<PLI> fac;
void solve(LL n)
{
    if (n == 4)
        return tmpfac.push_back(2);
    if (is_prime(n))
        return tmpfac.push_back(n);
    std::uniform_int_distribution<LL> dis(3, n - 1);
    LL p = phro(n, dis(eng));
    while (p == n) p = phro(n, dis(eng));
    solve(p), solve(n / p);
}
void get_phi(LL a)
{
    if (flag) return;
    if (a == 4)
        return void(p = 2), void(flag = 1);
    if (is_prime(a))
        return void(p = a), void(flag = 1);
    std::uniform_int_distribution<LL> dis(3, a - 1);
    LL p = phro(a, dis(eng));
    while (p == a) p = phro(a, dis(eng));
    get_phi(p);
}
LL ord(LL x)
{
    LL res = m / p * (p - 1);
    for (auto [p, cnt] : fac)
    {
        int t = 0;
        while (t < cnt && qpow(x, res / p, m) == 1) res /= p, ++ t;
    }
    return res;
}
int main()
{
    LL x, y;
    scanf("%lld %lld", &m , &n);
    get_phi(m);
    solve(p - 1);
    std::sort(tmpfac.begin(), tmpfac.end());
    tmpfac.erase(std::unique(tmpfac.begin(), tmpfac.end()), tmpfac.end());
    LL cur = p - 1;
    for (LL &x : tmpfac)
    {
        int t = 0;
        while (cur % x == 0) t ++, cur /= x;
        fac.push_back({x, t});
    }
    cur = m;
    int t = 0;
    while (cur % p == 0) ++ t, cur /= p;
    if (t > 1) fac.push_back({p, t - 1});
    while (n--)
    {
        scanf("%lld %lld", &x, &y);
        if (ord(x) % ord(y) == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}