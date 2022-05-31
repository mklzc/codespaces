// url: https://www.luogu.com.cn/problem/P3031
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
inline void read(T &t, Args &...args)
{
    read(t);
    read(args...);
}
const int N = 1e5 + 5;
int n, val, h[N];
inline int work()
{
    int ans = 0;
    return ans;
}
inline void rai()
{
    read(n, val);
    for (int i = 1; i <= n; i++)
        read(h[i]);
}
int main()
{
    freopen("in", "r", stdin);
    rai();
    printf("%d\n", work());
    return 0;
}