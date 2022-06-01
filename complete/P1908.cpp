// url: https://www.luogu.com.cn/problem/P1908
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x)
{
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
}
const int N = 5e5 + 10;
int n, a[N], b[N];
long long cnt;
void merge_sort(int l, int r)
{
    int mid = (l + r) >> 1;
    if (l >= r)
        return;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        if (j > r || (i <= mid && a[i] < a[j]))
            b[k] = a[i++];
        else
            b[k] = a[j++], cnt += mid - i + 1;
    for (int k = l; k <= r; k++)
        a[k] = b[k];
}
int main()
{
    read(n);
    int i;
    for (i = 1; i <= n; i++)
        read(a[i]);
    merge_sort(1, n);
    printf("%lld", cnt);
    return 0;
}