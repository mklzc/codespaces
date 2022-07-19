
// url: https://www.luogu.com.cn/problem/P2485
#include <bits/stdc++.h>
#define int long long
class BSGS
{
public:
    int mod, a, b, t;
    long long power;
    std::unordered_map<long long, int> hash;
    BSGS(int _a, int _b, int _mod) { a = _a, b = _b, mod = _mod, t = std::ceil(std::sqrt(mod)) + 1, power = 1; };
    int bsgs()
    {
        if ((a == 0 && b == 0) || (b == 1)) return 0;
        if (a == 0) return -1;
        for (int j = 0; j < t; j++)
            hash[b * power % mod] = j, power = power * a % mod;
        long long res = power;
        for (int i = 1; i <= t; i++)
        {
            auto iter = hash.find(power);
            int val = iter != hash.end() ? iter->second : mod;
            if (val != mod)
                return (((i * t - val) % mod + mod) % mod);
            power = power * res % mod;
        }
        return -1;
    }
};

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
        return void(x = 1), void(y = 0), a;
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y, y = z - y * (a / b);
    return d;
}
signed main()
{
    freopen("in", "r", stdin);
    int T, k, y, z, p;
    scanf("%lld %lld", &T, &k);
    auto case1 = [](int a, int b, int p)
    {
        int res = 1;
        for (; b; b >>= 1)
        {
            if (b & 1)
                res = 1ll * res * a % p;
            a = 1ll * a * a % p;
        }
        return res;
    };
    auto case2 = [&](int a, int b, int p)
    {
        int x, y;
        int d = exgcd(a, p, x, y);
        int res = p / d;
        if (b % d)
            puts("Orz, I cannot find x!");
        else
            printf("%lld\n", ((x * b / d) % res + res) % res);
    };
    if (k == 1)
        while (T--)
            scanf("%lld %lld %lld", &y, &z, &p),
                printf("%lld\n", case1(y, z, p));
    else if (k == 2)
        while (T--)
            scanf("%lld %lld %lld", &y, &z, &p),
                case2(y, z, p);
    else
    {
        while (T--)
        {
            scanf("%lld %lld %lld", &y, &z, &p);
            if (y && z && (y % p == 0 && z % p == 0))
                {puts("1");continue;}
            BSGS Run(y % p, z % p, p);
            int t = Run.bsgs();
            if (t == -1)
                puts("Orz, I cannot find x!");
            else
                printf("%lld\n", t);
        }
    }

    return 0;
}