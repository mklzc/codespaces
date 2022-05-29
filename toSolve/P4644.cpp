// url: https://www.luogu.com.cn/problem/P4644
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
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    x = x * w;
}
template <typename T, typename... Args>
inline void read(T &t, Args&... args)
{
    read(t);
    read(args...);
}

const int N = 10005;
int n, m, E;
inline void rai()
{
    read(n, m, E);
}
int main()
{
    return 0;
}