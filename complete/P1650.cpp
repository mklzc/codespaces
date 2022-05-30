// url: https://www.luogu.com.cn/problem/P1650
// Author: lzc
#include <bits/stdc++.h>
#define Max(x) x--
#define Min(x) x++
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
const int N = 2005;
int n, a[N], b[N];
int work()
{
    int *tMin = a + 1, *tMax = a + n, *qMin = b + 1, *qMax = b + n, res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (*tMax > *qMax)
            Max(tMax), Max(qMax), res += 200;
        else if (*tMax < *qMax)
            Min(tMin), Max(qMax), res -= 200;
        else if (*tMax == *qMax)
            if (*tMin > *qMin)
                Min(tMin), Min(qMin), res += 200;
            else if (*tMin < *qMax)
                Min(tMin), Max(qMax), res -= 200;
            else
                Min(tMin), Max(qMax);
    }
    return res;
}
inline void rai()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= n; i++)
        read(b[i]);
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
}
int main()
{
    rai();
    printf("%d\n", work());
    return 0;
}