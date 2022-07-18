// url: https://www.luogu.com.cn/problem/P5517
#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
using ull = unsigned long long;
using uint = unsigned int;
using LL = long long;
ull sd;int op;
inline void init() { scanf("%llu %d", &sd, &op); }
inline ull ull_rand() { return void(sd ^= sd << 43), void(sd ^= sd >> 29), void(sd ^= sd << 34), sd; }
inline ull Rand()
{
    if (op == 0) return ull_rand() % USHRT_MAX + 1;
    if (op == 1) return ull_rand() % UINT_MAX + 1;
    else return ull_rand();
}

const LL mod = 1e9 + 7, scope = (1 << 16) + 5;
int SQR;
LL sqr[scope], linear[scope];
inline void prework(int x)
{
    SQR = std::sqrt(mod) + 1;
    linear[0] = sqr[0] = 1;
    for (int i = 1; i <= SQR; i++)
        linear[i] = linear[i - 1] * x % mod;
    for (int i = 1; i <= SQR; i++)
        sqr[i] = sqr[i - 1] * linear[SQR] % mod;
}
inline LL light_qpow(LL x) { return linear[x % SQR] * sqr[x / SQR] % mod; }
const LL inv = 281250002;
int main()
{
    int T;
    prework(3);
    LL ans = 0;
    scanf("%d", &T);
    init();
    while (T--)
    {
        ull n = Rand();
        LL res = (n & 1) ? 51 : 21, mul = (4 * LL(n % mod) - 13 + mod) % mod;
        res = (res + mul * light_qpow((n + 2) % (mod - 1))) % mod;
        ans ^= (res * inv) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}