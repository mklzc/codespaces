#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 53, mod = 10000007;
LL qpow(LL x, LL y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
LL f[Maxn][Maxn], n;
int cnt, digit[Maxn], I;
LL dfs(int pos, bool limit, int sum)
{
    if(!pos) return sum == I;
    if (!limit && ~f[pos][sum]) return f[pos][sum];
    int up = limit ? digit[pos] : 1;
    LL res = 0;
    for (int i = 0; i <= up; i++)
        res += dfs(pos - 1, limit && i == up, sum + (i == 1));
    if (!limit) f[pos][sum] = res;
    return res;
}

LL solve(LL x)
{
    cnt = 0;
    while (x)
        digit[++cnt] = x & 1, x >>= 1;
    LL ans = 1;
    for (int i = 1; i <= Maxn; i++)
    {
        I = i, memset(f, -1, sizeof(f));
        ans = (ans * qpow(i, dfs(cnt, true, 0))) % mod;
    }
    return ans;
}
int main()
{
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
    return 0;
}