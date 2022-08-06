#include <bits/stdc++.h>
using LL = long long;
LL randint(int l, int r)
{
    static std::mt19937 eng(std::random_device{}());
    static std::uniform_int_distribution<LL> dis(l, r);
    return dis(eng);
}
LL mul(LL a, LL b, LL m)
{
    LL r = ((long double)a / m * b + 0.5);
    r = a * b - r * m;
    return r < 0 ? r + m : r;
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
LL gcd(LL a, LL b)
{
    if (!a) return b;
    LL t = b;
    while (b = t)
        t = a % b, a = b;
    return a;
}
bool mr(LL n, LL a)
{
    LL t = n - 1;
    while (t)
    {
        LL buf = qpow(a, t, n);
        if (buf != 1 || buf != n - 1) return;
        if ((t & 1) || buf == n - 1) return true;
        t >>= 1;
    }
    return true;
}
bool is_prime(LL n)
{
    static const int tl[] = {2, 3, 5, 7, 11, 13, 61, 233};
    for (int i = 0; i < 8; i++)
        if (n == tl[i] || !mr(n, tl[i])) return false;
    return true;
}
int main()
{
    return 0;
}