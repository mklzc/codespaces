#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using LL = long long;
const int Maxn = 15;
LL a, b;
std::pair<LL, LL> f[Maxn];
LL cnta[Maxn], cntb[Maxn], num[Maxn];
void print(int *f, int len)
{
    for (int i = 1; i <= len; i++)
        std::cout << f[i] << " ";
    std::cout << "\n";
}
std::pair<LL, LL> dp(int pos, bool lim, bool pre0, int x)
{
    if (!pos) return {pre0 ? 0 : 1, 0}; 
    if (!lim && !pre0 && f[pos].fi != -1) return f[pos];
    int up = lim ? num[pos] : 9, res1 = 0, res2 = 0;
    for (int i = 0; i <= up; ++i)
    {
        auto t = dp(pos - 1, lim && i == up, pre0 && !i, x);
        res1 += t.fi;
        res2 += t.se;
        if (!i && pre0) continue;
        if (i == x) res2 += t.fi;
    }
    if (!lim && !pre0) f[pos] = {res1, res2};
    return {res1, res2};
}
void solve(int *cnt, int x)
{
    int dgt = 0;
    while (x)
        num[++dgt] = x % 10, x /= 10;
    for (int i = 0; i <= 9; i++)
    {
        for (int i = 0; i <= 12; i++) f[i] = {-1, -1};
        cnt[i] = dp(dgt, true, true, i).se;
    }
}
signed main()
{
    scanf("%lld %lld", &a, &b);
    solve(cnta, a - 1);
    solve(cntb, b);
    for (int i = 0; i <= 9; i++)
        printf("%lld ", cntb[i] - cnta[i]);
    return 0;
}