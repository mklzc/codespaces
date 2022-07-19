#include <bits/stdc++.h>
using LL = long long;
class BSGS{
public:
    LL mod, a, b, t, power;
    std::unordered_map<LL, int> hash;
    BSGS(LL _a, LL _b, int _mod){a = _a, b = _b, mod = _mod, t = std::ceil(std::sqrt(mod)), power = 1;};
    int work()
    {
        hash.clear();
        for (int j = 0; j < t; j++)
            hash[b * power % mod] = j, power = power * a % mod;
        LL res = power;
        for (int i = 1; i <= t; i++)
        {
            auto iter = hash.find(power);
            int val = iter != hash.end() ? iter->second : mod;
            if (val != mod)
                return i * t - val;
            power = power * res % mod;
        }
        return -10000;
    }
}bsgs(0, 0, 0);
void exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
        return void(x = 1), void(y = 0);
    exgcd(b, a % b, x, y);
    LL z = x;
    x = y, y = z - y * (a / b);
}
LL inv(LL a, int mod) {LL x, y; exgcd(a, mod, x, y);return (x % mod + mod) % mod;}

LL dfs(LL a, LL b, LL mod)
{
    if (a == b) return 1;
    LL d = std::__gcd(a, mod);
    if (d == 1) return void(bsgs = BSGS(a, b, mod)), bsgs.work();
    if (b % d) return -10000;
    mod /= d;
    return dfs(a % mod, (b / d) * inv(a / d, mod) % mod, mod) + 1;
}

int main()
{
    LL a, b;
    int mod;
    auto work = [](LL a, LL b, int mod)->LL{
        if (b == 1 || mod == 1) return 0;
        if (!a) return b ? -1 : 1;
        if (b == 1) return 0;
        return dfs(a, b, mod);
    };
    while (1)
    {
        scanf("%lld %d %lld", &a, &mod, &b);
        if (!mod) break;
        a %= mod, b %= mod;
        LL ans = work(a, b, mod);
        if (ans >= 0) printf("%lld\n", ans);
        else puts("No Solution");
    }
    return 0;
}