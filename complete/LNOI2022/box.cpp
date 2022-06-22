#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
inline void read(T &x)
{
    x = 0;
    T w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    x = x * w;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args)
{
    read(x);
    read(args...);
}
typedef long long LL;
const int N = 5e5 + 5, mod = 998244353;
int n;
LL a[N], w[N], t[N], s[N], ans;
inline void dfs(int x, LL sum)
{
    if (sum > s[n]) return;
    if (x == n)
    {
        for (int i = 1; i <= n - 1; i++)
            ans += abs(s[i] - t[i]) * w[i] % mod;
        return;
    }
    for (int i = 0; i <= s[n]; i++)
    {
        t[x] = t[x - 1] + i;
        dfs(x + 1, sum + i);
        t[x] = t[x - 1] - i;
    }
}
inline LL work()
{
    dfs(1, 0);
    return (ans % mod + mod) % mod;
}
inline void rai()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]), s[i] = (s[i - 1] + a[i]) % mod;
    for (int i = 1; i <= n - 1; i++)
        read(w[i]);
}
int main()
{
    int Testcase;
    read(Testcase);
    while (Testcase--)
    {
        ans = 0;
        rai();
        printf("%lld\n", work());
    }
    return 0;
}