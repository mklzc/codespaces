#include <bits/stdc++.h>
using LL = long long;
const int lim = 9 * 17;
LL a, b, f[20][lim + 10][lim + 10];
int digit[20], mod;
LL dfs(int pos, int sum, bool limit, int num)
{
    if (!pos) return !num && sum == mod;
    if (!limit && f[pos][sum][num] != -1) return f[pos][sum][num];
    int up = limit ? digit[pos] : 9;
    LL res = 0;
    for (int i = 0; i <= up; i++)
        if (sum + i <= mod)
            res += dfs(pos - 1, sum + i, limit && i == up, (num * 10ll + i) % mod);
    if (!limit) f[pos][sum][num] = res;
    return res;
}
int cnt = 0;
LL calc(LL val)
{
    cnt = 0;
    while (val)
        digit[++cnt] = val % 10, val = val / 10;
    LL ans = 0;
    for (int i = 1; i <= 9 * cnt; i++){
        memset(f, -1, sizeof(f));
        mod = i;
        ans += dfs(cnt, 0, true, 0);
    }
    return ans;
}
int main()
{
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", calc(b) - calc(a - 1));
    return 0;
}