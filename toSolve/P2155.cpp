// url: https://www.luogu.com.cn/problem/P2155
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
const int N = 65, M = 1e7 + 4;
int T, R, n, m;
int primes[N], cnt, inv[N];
void psplit(int x)
{
    memset(primes, 0, sizeof(primes)), cnt = 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            primes[++cnt] = i;
            while (x % i == 0) x /= i;
        }
    if (x > 1) primes[++cnt] = x;
}
void init()
{
    inv[1] = inv[0] = 1;
    for (int i = 2; i < M; i++)
        inv[i] = (R - R / i) * inv[i - 1] * inv[R % i] % R;
    for (int i = 2; i < M; i++)
        inv[i] = inv[i] * inv[i - 1] % R;
}

inline void raw()
{
    scanf("%d %d", &T, &R);
    typedef long long LL;
    while (T--)
    {
        scanf("%d %d", &n, &m);
        psplit(m);
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
        }
        for (int i = 1; i <= cnt; i++)
        {
        }
    }
}
int main() { return raw(), 0; }