// url: https://www.luogu.com.cn/problem/P5142
#include <bits/stdc++.h>
#define ls t[p].l
#define rs t[p].r
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
const int N = 1e5 + 10;
typedef long long LL;
const LL mod = 1000000007;
struct Node
{
    int l, r;
    LL sum, sqsum;
} t[N << 2];
int idx, CME, END, POS;
LL VAL, b;
inline void pushup(int p)
{
    t[p].sum = (t[ls].sum + t[rs].sum) % mod;
    t[p].sqsum = (t[ls].sqsum + t[rs].sqsum) % mod;
}

int build(int l, int r)
{
    int p = ++idx;
    if (l == r)
        return void(read(b)), void(t[p].sum = b % mod), void(t[p].sqsum = b * b % mod), p;
    int mid = (l + r) >> 1;
    t[p].l = build(l, mid);
    t[p].r = build(mid + 1, r);
    return pushup(p), p;
}

void modify(int p, int l, int r)
{
    if (l == r)
        return void(t[p].sum = VAL % mod), void(t[p].sqsum = VAL * VAL % mod);
    int mid = (l + r) >> 1;
    if (POS <= mid)
        modify(ls, l, mid);
    else
        modify(rs, mid + 1, r);
    pushup(p);
}
LL querySum(int p, int l, int r)
{
    if (CME <= l && r <= END)
        return t[p].sum;
    int mid = (l + r) >> 1;
    LL val = 0;
    if (CME <= mid)
        val = (val + querySum(ls, l, mid)) % mod;
    if (mid < END)
        val = (val + querySum(rs, mid + 1, r)) % mod;
    return val;
}
LL querySqsum(int p, int l, int r)
{
    if (CME <= l && r <= END)
        return t[p].sqsum;
    LL val = 0;
    int mid = (l + r) >> 1;
    if (CME <= mid)
        val = (val + querySqsum(ls, l, mid)) % mod;
    if (mid < END)
        val = (val + querySqsum(rs, mid + 1, r)) % mod;
    return val;
}
LL qpow(LL x, LL y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
    }
    return res;
}
int raw()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n, m, op;
    read(n, m);
    build(1, n);
    while (m--)
    {
        read(op);
        if (op == 1)
            read(POS, VAL), modify(1, 1, n);
        else
        {
            read(CME, END);
            LL Sqsum = querySqsum(1, 1, n), Sum = querySum(1, 1, n), len = END - CME + 1;
            LL inv = qpow(len, mod - 2);
            LL Ans = Sqsum * inv % mod - (Sum * inv % mod) * (Sum * inv % mod) % mod;
            printf("%lld\n", (Ans % mod + mod) % mod);
        }
    }
    return 0;
}
int main() { return raw(); }