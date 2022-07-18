#include <cstdio>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using LL = long long;
class BSGS{
public:
    LL mod, a, b, t, power;
    std::unordered_map<LL, LL> hash;
    BSGS(LL _a, LL _b, LL _mod){a = _a, b = _b, mod = _mod, t = std::ceil(std::sqrt(mod)) + 1, power = 1;};
    LL mul(LL x, LL y) {
        LL res = 0;
        for (; y; y >>= 1) {if (y & 1) res = (res + x) % mod;x = (x + x) % mod;}
        return res;
    }
    LL bsgs()
    {
        for (LL j = 0; j < t; j++)
            hash[mul(b, power) % mod] = j, power = mul(power, a) % mod;
        LL res = power;
        for (LL i = 1; i <= t; i++)
        {
            auto iter = hash.find(power);
            LL val = iter != hash.end() ? iter->second : mod;
            if (val != mod)
                return i * t - val;
            power = mul(power, res);
        }
        return -1;
    }
};
int main()
{
    LL k, m;
    scanf("%lld %lld", &k, &m);
    BSGS work(10, (9 * k + 1) % m, m);
    printf("%lld\n", work.bsgs());
    return 0;
}