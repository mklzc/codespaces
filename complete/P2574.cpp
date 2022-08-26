#include <bits/stdc++.h>
const int Maxn = 2e5 + 10;
int n, m;
char s[Maxn];
struct seg {
    int l, r;
    int dat, add;
} t[Maxn << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
inline void pushup(int p) { t[p].dat = t[rs].dat + t[ls].dat; }
inline void pushdown(int p)
{
    if (!t[p].add) return;
    t[rs].add ^= 1;
    t[ls].add ^= 1;
    t[ls].dat = (t[ls].r - t[ls].l + 1) - t[ls].dat;
    t[rs].dat = (t[rs].r - t[rs].l + 1) - t[rs].dat;
    t[p].add = 0;
}
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].dat = t[p].add = 0;
    if (l == r)
    {
        t[p].dat = (s[l] != '1') ? 0 : 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
void modify(int p, int ql, int qr)
{
    if (ql <= t[p].l && t[p].r <= qr)
    {
        t[p].dat = (t[p].r - t[p].l + 1) - t[p].dat;
        t[p].add ^= 1;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    pushdown(p);
    if (ql <= mid)
        modify(ls, ql, qr);
    if (mid < qr)
        modify(rs, ql, qr);
    pushup(p);
}
int query(int p, int ql, int qr)
{
    if (ql <= t[p].l && t[p].r <= qr)
        return t[p].dat;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1, val = 0;
    if (ql <= mid)
        val += query(ls, ql, qr);
    if (mid < qr)
        val += query(rs, ql, qr);
    return val;
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    build(1, 1, n);
    int op, l, r;
    while (m--)
    {
        scanf("%d %d %d", &op, &l, &r);
        if (op == 0)
            modify(1, l, r);
        else
            printf("%d\n", query(1, l, r));
    }
    return 0;
}