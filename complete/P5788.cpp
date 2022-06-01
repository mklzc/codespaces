// url: https://www.luogu.com.cn/problem/P5788
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
const int N = 3e6 + 5;
int n, a[N], ans[N];
deque<int> q;
inline void work()
{
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[q.back()] < a[i])
            ans[q.back()] = i, q.pop_back();
        q.push_back(i);
    }
}
inline void rai()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
}
int main()
{
    rai();
    work();
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
