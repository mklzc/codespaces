#include <bits/stdc++.h>

const int Maxn = 100010;
int n, ans, x[Maxn];
std::vector<int> a;
std::set<std::vector<int>> vis;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void dfs()
{
    if (vis.find(a) != vis.end()) return;
    vis.insert(a), ans++;
    for (int i = 0; i + 1 < n; i++)
    {
        if (gcd(a[i], a[i + 1]) != 1) continue;
        std::swap(a[i], a[i + 1]);
        dfs(); std::swap(a[i], a[i + 1]);
    }
}
using LL = long long;
bool sub()
{
    for (int i = 0; i < n; i++)
        if (x[i] > 3) return false;
    static const int mod = 998244353;
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    auto qpow = [](LL x, LL y) ->LL{
        LL res = 1;
        for (; y; y >>= 1) {
            if (y & 1) res = res * x % mod;
            x = x * x % mod;
        } return res;
    };
    auto Factorial = [](int x) ->LL{
        LL res = 1;
        for (int i = 1; i <= x; i++)
            res = res * i % mod;
        return res;
    };
    LL sav = Factorial(n);
    for (int i = 0; i < n; i++)
        cnt[x[i]]++;
    for (int i = 1; i <= 3; i++)
    {
        if (!cnt[i]) continue;
        sav = sav * qpow(Factorial(cnt[i]), mod - 2) % mod;
    }
    printf("%lld\n", sav);
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    if (sub()) return 0;
    for (int i = 0; i < n; i++)
        a.emplace_back(x[i]);
    dfs();
    printf("%d", ans);
    return 0;
}