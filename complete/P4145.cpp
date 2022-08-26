#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 1e5 + 10;
LL a[Maxn]; int n, m;
struct Node {
    int l, r;
    LL sum, mx;
} t[Maxn << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) {t[p].sum = t[ls].sum + t[rs].sum, t[p].mx = std::max(t[ls].mx, t[rs].mx);}
void build(int p, int l, int r)
{
    t[p].sum = t[p].mx = 0;
    t[p].l = l, t[p].r = r;
    if (l == r) return void(t[p].sum = t[p].mx = a[l]);
    int mid = (l + r) >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    pushup(p);
}
LL query_Max(int p, int ql, int qr)
{
    if (ql <= t[p].l && t[p].r <= qr) return t[p].mx;
    int mid = (t[p].l + t[p].r) >> 1; LL val = 0;
    if (ql <= mid) val = std::max(val, query_Max(ls, ql, qr));
    if (mid < qr) val = std::max(val, query_Max(rs, ql, qr));
    return val;
}
void modify(int p, int ql, int qr)
{
    if (t[p].l == t[p].r) return void(t[p].sum = std::sqrt(t[p].sum)), void(t[p].mx = std::sqrt(t[p].mx));
    int mid = (t[p].l + t[p].r) >> 1;
    if (ql <= mid && query_Max(1, t[p].l, mid) > 1) modify(ls, ql, qr);
    if (mid < qr && query_Max(1, mid + 1, t[p].r) > 1) modify(rs, ql, qr);
    pushup(p);
}
LL query(int p, int ql, int qr)
{
    if (ql <= t[p].l && t[p].r <= qr) return t[p].sum;
    int mid = (t[p].l + t[p].r) >> 1; LL val = 0;
    if (ql <= mid) val += query(ls, ql, qr);
    if (mid < qr) val += query(rs, ql, qr);
    return val;
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (l > r) std::swap(l, r);
        if (op == 1) printf("%lld\n", query(1, l, r));
        else modify(1, l, r);
    }
    return 0;
}