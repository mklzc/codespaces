#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') { if (ch == '-') w = -1;ch = getchar();}
        while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
void print(int *f, int len)
{
    for (int i = 1; i <= len; i++)
        std::cout << f[i] << " ";
    std::cout << "\n";
}
const int Maxn = 1e5 + 5, mod = 998244353;
int n, a[Maxn], num[Maxn], s[11][Maxn];
bool sub2 = false, sub3 = false;
int qpow(int x, int y)
{
    long long res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = res * x % mod;
        x = (int)(1ll * x * x % mod);
    }
    return (int)res;
}
bool subtask2_judge()
{
    for (int i = 1; i <= n; i++)
        num[a[i]]++;
    for (int i = 1; i <= Maxn; i++)
        if (num[a[i]] > 1) return false;
    return true;
}
int subtask2(int l, int r)
{
    int ans = qpow(2, r - l + 1);
    printf("%d\n", ans);
    return ans;
}
bool subtask3_judge()
{
    for (int i = 1; i <= n; i++)
        if (a[i] > 10) return false;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == i) s[i][j] = s[i][j - 1] + 1;
            else s[i][j] = s[i][j - 1];
        }
    }
    return true;
}
int subtask3(int l, int r)
{
    long long ans = 1;
    for (int i = 1; i <= 10; i++)
        ans = ans * (s[i][r] - s[i][l - 1] + 1) % mod;
    printf("%lld\n", ans);
    return (int)ans;
}
int ls[Maxn];

int subtask1(int l, int r)
{
    int st = 0;
    for (int i = l; i <= r; i++)
        num[a[i]]++, ls[++st] = a[i];
    long long ans = 1;
    for (int i = 1; i <= st; i++)
    {
        ans = (ans * (num[ls[i]] + 1)) % mod;
        num[ls[i]] = 0;
    }
    printf("%lld\n", ans);
    return (int)ans;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    read(n);
    rep(i, 1, n) read(a[i]);
    sub2 = subtask2_judge();
    memset(num, 0, sizeof(num));
    sub3 = subtask3_judge();
    int q, l, r, lst = 0;
    read(q);
    while (q--)
    {
        read(l, r);
        l ^= lst, r ^= lst;
        if (sub2) lst = subtask2(l, r);
        else if (sub3) lst = subtask3(l, r);
        else lst = subtask1(l, r);
    }
	return 0;
}