// url: https://www.luogu.com.cn/problem/P3374
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
const int N = 5e5 + 5;
typedef long long LL;
struct Node
{
    int l, r;
    LL sum;
} t[N << 2];
int n, m, idx, POS, CME, END;
LL VAL, a;
inline void pushup(int p) { t[p].sum = t[t[p].l].sum + t[t[p].r].sum; }
int build(int l, int r)
{
    int p = ++idx;
    if (l == r)
        return void(read(a)), void(t[p].sum = a), p;
    int mid = (l + r) >> 1;
    t[p].l = build(l, mid);
    t[p].r = build(mid + 1, r);
    return pushup(p), p;
}
void modify(int p, int l, int r)
{
    if (l == r) 
        return void(t[p].sum += VAL);
    int mid = (l + r) >> 1;
    if (POS <= mid) modify(t[p].l, l, mid);
    else modify(t[p].r, mid + 1, r);
    pushup(p);
}
LL query(int p, int l, int r)
{
    if (CME <= l && r <= END)
        return t[p].sum;
    LL val = 0;
    int mid = (l + r) >> 1;
    if (CME <= mid)
        val += query(t[p].l, l, mid);
    if (END > mid)
        val += query(t[p].r, mid + 1, r);
    return val;
}
inline int raw()
{
    read(n, m);
    build(1, n);
    int op;
    while (m--)
    {
        read(op);
        if (op == 1)
            read(POS, VAL), modify(1, 1, n);
        else
            read(CME, END), printf("%lld\n", query(1, 1, n));
    }
    return 0;
}
int main() { return raw(); }