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
int n, val, s[N], t[N];
typedef long long LL;
LL cnt;

void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        if (j > r || (i <= mid && s[i] <= s[j]))
            t[k] = s[i++];
        else t[k] = s[j++], cnt += 1ll * mid - i + 1;
    for (int k = l; k <= r; k++)
        s[k] = t[k];
}
inline LL work()
{
    merge_sort(0, n);
    LL total = 1ll * n * (n + 1) / LL(2);
    return total - cnt;
}
inline void rai()
{
    read(n, val);
    int h;
    for (int i = 1; i <= n; i++) {
        read(h);
        h = (h >= val) ? 1 : -1;
        s[i] = s[i - 1] + h;
    }
}
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}