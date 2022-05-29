// url: https://www.luogu.com.cn/problem/P7305
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
const int N = 1e5 + 5;
struct Node
{
    int x, y;
}t[N];
int n, m;
inline void rai()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
        read(t[i].x);
    for (int i = 1; i <= m; i++)
        read(t[i].y);
}
int main()
{
    rai();
    return 0;
}