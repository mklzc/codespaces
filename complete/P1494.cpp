// url: https://www.luogu.com.cn/problem/P1494
// Author: lzc
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
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

typedef long long LL;
const int N = 50005, M = 300;
struct Node
{
    int l, r, id, ans;
};
Node a[N];
int n, m, t, c[N], num[N], nl, nr, Ans, L[M], R[M];
bool cmp_l(Node a, Node b) { return a.l < b.l; }
bool cmp_r(Node a, Node b) { return a.r < b.r; }
bool cmp_id(Node a, Node b) { return a.id < b.id; }
LL C(int x) { return (LL)(x) * (LL)(x - 1) / 2; }
void calc(int x, int K)
{
    Ans -= (num[c[K]] - 1) * num[c[K]] / 2;
    num[c[K]] += x;
    Ans += (num[c[K]] - 1) * num[c[K]] / 2;
}
inline int perform(Node x)
{
    while (nl > x.l) nl--, calc(1, nl);
    while (nl < x.l) calc(-1, nl), nl++;
    while (nr < x.r) nr++, calc(1, nr);
    while (nr > x.r) calc(-1, nr), nr--;
    return Ans;
}
inline void rai()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
        read(c[i]);
    for (int i = 1; i <= m; i++)
        read(a[i].l, a[i].r), a[i].id = i;
    sort(a + 1, a + m + 1, cmp_l);
    t = sqrt(m);
    for (int i = 1; i <= t; i++)
        L[i] = (i - 1) * t + 1, R[i] = i * t;
    if (R[t] < m) t++, L[t] = R[t - 1] + 1, R[t] = m;
    for (int i = 1; i <= t; i++)
        sort(a + L[i], a + R[i] + 1, cmp_r);
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline void divgcd(int x, int y)
{
    int d = gcd(C(y), x);
    if (x) printf("%d/%d\n", x / d, C(y) / d);
    else puts("0/1");
}
int main()
{
    rai();
    for (int i = 1; i <= t; i++)
    {
        memset(num, 0, sizeof(num));
        nl = nr = Ans = 0;
        nl = a[L[i]].l, nr = a[L[i]].r;
        for (int j = a[L[i]].l; j <= a[L[i]].r; j++)
        {
            Ans -= (num[c[j]] - 1) * (num[c[j]]) / 2;
            num[c[j]]++;
            Ans += (num[c[j]] - 1) * num[c[j]] / 2;
        }
        a[L[i]].ans = Ans;
        for (int j = L[i] + 1; j <= R[i]; j++)
            a[j].ans = perform(a[j]);
    }
    sort(a + 1, a + m + 1, cmp_id);
    for (int i = 1; i <= m; i++)
        if (a[i].l != a[i].r) divgcd(a[i].ans, a[i].r - a[i].l + 1);
        else puts("0/1");
    return 0;
}