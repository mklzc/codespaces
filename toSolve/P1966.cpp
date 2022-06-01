// url: https://www.luogu.com.cn/problem/P1966
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
}
template <typename T, typename... Args>
inline void read(T &x, Args&... args)
{
    read(x);
    read(args...);
}
typedef long long LL;
const int N = 1e5 + 5;
int n;
LL a[N], b[N], cnt;
vector<int> q;
inline int Find(int x) {
    return lower_bound(q.begin(), q.end(), x) - q.begin();
}
inline LL work()
{
}
inline void rai()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]), q.push_back(a[i]);
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    for (int i = 1; i <= n; i++)
        a[i] = Find(a[i]);
    for (int i = 1; i <= n; i++)
        read(b[i]), q.push_back(b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
}
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}