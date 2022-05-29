// url: https://www.luogu.com.cn/problem/P7913
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
    int a, b;
};
Node fr[N], dm[N];
int n, m1, m2;
void rai()
{
    read(n, m1, m2);
    int a, b;
    for (int i = 1; i <= m1; i++)
        read(dm[i].a, dm[i].b);
    for (int i = 1; i <= m2; i++)
        read(fr[i].a, fr[i].b);
}

int main()
{
    return 0;
}