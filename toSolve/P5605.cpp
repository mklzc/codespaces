#include <bits/stdc++.h>
using LL = long long;
template <typename Tp>
Tp randint(Tp l, Tp r)
{
    static mt19937 eng(time(0));
    std::uniform_int_distribution<T> dis(l, r);
    return dis(eng);
}
LL gcd(LL a, LL b)
{
    return (!b) ? a : gcd(b, a % b);
}
bool is_prime(LL n)
{
}
LL prho(LL n)
{
    if (is_prime(n))
        return n;
}
int main()
{
    return 0;
}