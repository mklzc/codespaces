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
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args)
{
    read(x);
    read(args...);
}

typedef long long LL;
const int N = 1e5 + 5, mod = 99999997;
struct Node
{
    int val, id;
};
LL a[N], b[N], cnt;
int x[N], tmp[N], n;
vector<int> q;
inline int Find(int x) { return lower_bound(q.begin(), q.end(), x) - q.begin(); }
void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        if (j > r || (x[i] <= x[j] && i <= mid))
            tmp[k] = x[i++];
        else
            tmp[k] = x[j++], cnt = (cnt + mid - i + 1) % mod;
    for (int k = l; k <= r; k++)
        x[k] = tmp[k];
}
inline LL work()
{

    merge_sort(0, n - 1);
    return cnt;
}
inline void rai()
{
    read(n);
}
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}