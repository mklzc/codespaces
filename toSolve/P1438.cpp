#include <bits/stdc++.h>
#define ls t[p].l
#define rs t[p].r
const int Maxn = 1e5 + 5;
using LL = long long;
int n, m, a[Maxn], idx;
struct Node
{
    int l, r;
    LL sum, add;
}t[Maxn << 2];
int st, ed;
LL val;
inline void pushup(int p)
{
    t[p].sum = t[ls].sum + t[rs].sum;
}
inline void pushdown(int p, int l, int r)
{
    if (!t[p].add) return;
    t[ls].add += t[p].add;
    t[rs].add += t[p].add;
    int mid = (l + r) >> 1;
    t[ls].sum += 1ll * (mid - l + 1) * t[p].add;
    t[rs].sum += 1ll * (r - mid) * t[p].add;
    t[p].add = 0;
}
int build(int l, int r)
{
    int p = ++idx;
    if (l == r)
    {
        t[p].sum = a[l] - a[l - 1];
        return p;
    }
    int mid = (l + r) >> 1;
    t[p].l = build(l, mid);
    t[p].r = build(mid + 1, r);
    pushup(p);
    return p;
}
void modify(int p, int l, int r)
{
    if (st <= l && r <= ed)
    {
        t[p].sum += 1ll * (r - l + 1) * val;
        t[p].add += val;
        return;
    }
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    if (st <= mid)
        modify(ls, l, mid);
    if (mid < ed)
        modify(rs, mid + 1, r);
    pushup(p);
}
LL query(int p, int l, int r)
{
    if (st <= l && r <= ed)
        return t[p].sum;
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    LL buf = 0;
    if (st <= mid)
        buf += query(ls, l, mid);
    if (mid < ed)
        buf += query(rs, mid + 1, r);
    pushup(p);
    return buf;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ++n;
    build(1, n);
    int op, l, r, k, d, p;
    while (m--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d %d %d", &l, &r, &k, &d);
            st = l, ed = l, val = k;
            modify(1, 1, n);
            st = l + 1, ed = r, val = d;
            modify(1, 1, n);
            st = r + 1, ed = r + 1, val = -(1ll * (r - l) * d + k);
            modify(1, 1, n);
        }
        else
        {
            scanf("%d", &p);
            st = 1, ed = p;
            if (query(1, 1, n) == 1498)
            {
                std::cerr << p << "\n";
            }
            printf("%lld\n", query(1, 1, n));
        }
    }
    return 0;
}