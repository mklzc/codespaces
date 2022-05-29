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
int n, m, len, a[N], b[N];
bool check(int x)
{
}
inline int work()
{
    int l = 0, r = 1000000000;
    while (l < r)
    {
        cout << l << " " << r << endl;
        int mid = (l + r - 1) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
inline void rai()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= m; i++)
        read(b[i]);
    len = min(m, n);
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
}
int main()
{
    freopen("in", "r", stdin);
    rai();
    printf("%d\n", work());
    return 0;
}