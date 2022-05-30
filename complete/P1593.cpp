// url: https://www.luogu.com.cn/problem/P1593
// Author: lzc
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
const int N = 5e5 + 10, mod = 9901;
int a, b, cnt;
struct Node
{
    int p, c;
}t[N];
inline void split(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (!(x % i))
        {
            t[++cnt].p = i, t[cnt].c = 0;
            while (!(x % i))
                x /= i, t[cnt].c++;
        }
    if (x > 1) t[++cnt].p = x, t[cnt].c++;
    for (int i = 1; i <= cnt; i++)
        t[i].c *= b;
}
inline LL qpow(int x, int y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = (1ll * res * x) % mod;
        x = (1ll * x * x) % mod;
    }
    return res;
}
inline LL work() 
{
    if (!a) return 0;
    split(a);
    LL ans = 1;
    for (int i = 1; i <= cnt; i++)
        if ((t[i].p - 1) % mod == 0) ans = ans * (1 + t[i].c) % mod;
        else  ans = (ans * (qpow(t[i].p, t[i].c + 1) - 1) % mod * qpow(t[i].p - 1, mod - 2)) % mod;
    return ((ans % mod) + mod) % mod;
}
inline void rai() {read(a, b); }
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}