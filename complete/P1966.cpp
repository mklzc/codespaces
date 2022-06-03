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
LL cnt;
int x[N], tmp[N], n;
struct Node
{
    LL val;
    int id;
}a[N], b[N];
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
    merge_sort(1, n);
    return cnt;
}
bool cmp(Node p, Node q) {
    return p.val < q.val;
}
vector<int> q;
inline int Find(int x) {
    return lower_bound(q.begin(), q.end(), x) - q.begin();
}
inline void discrete(char ch)
{
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    if (ch == 'a')
        for (int i = 1; i <= n; i++)
            a[i].val = Find(a[i].val);
    else 
        for (int i = 1; i <= n; i++)
            b[i].val = Find(b[i].val);
    q.clear();
}
inline void rai()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i].val), a[i].id = i, q.push_back(a[i].val);
    discrete('a');
    for (int i = 1; i <= n; i++)
        read(b[i].val), b[i].id = i, q.push_back(b[i].val);
    discrete('b');
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        x[b[i].id] = a[i].id;
}
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}
/*
sample input:
50
41 29 19 46 13 28 47 17 45 4 34 14 37 7 30 24 27 9 11 15 50 8 39 32 3 42 10 16 31 6 1 43 21 36 2 23 26 49 33 12 40 35 22 48 5 25 20 18 44 38 
43 13 32 28 41 3 8 20 37 22 40 34 33 24 47 21 39 14 17 6 18 50 19 26 45 44 9 30 42 1 35 49 15 5 23 16 29 27 36 38 2 25 46 48 7 31 4 11 10 12 

sample output:
540
*/