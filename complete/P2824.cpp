#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
int n, m, Q, Now, a[Maxn], b[Maxn];
struct Query {
    int opt, l, r;
} q[Maxn];
struct Seg {
    int l, r, sum, tag;
} t[Maxn << 2];
void pushup(const int p) { t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum; }
int len(int p) { return t[p].r - t[p].l + 1; }
void pushdown(const int p)
{
    if (t[p].tag == -1) return;
    t[p << 1].tag = t[p << 1 | 1].tag = t[p].tag;
    t[p << 1].sum = t[p].tag * len(p << 1);
    t[p << 1 | 1].sum = t[p].tag * len(p << 1 | 1);
    t[p].tag = -1;
}
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].tag = -1, t[p].sum = 0;
    if (l == r) return void(t[p].sum = (a[l] > Now));
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modify(int p, const int ql, const int qr, const int val)
{
    if (ql > qr) return;
    if (ql <= t[p].l && t[p].r <= qr)
        return t[p].tag = val, t[p].sum = val * len(p), void();
    pushdown(p);
    int mid = (t[p].r + t[p].l) >> 1;
    if (ql <= mid) modify(p << 1, ql, qr, val);
    if (mid < qr) modify(p << 1 | 1, ql, qr, val);
    pushup(p);
}
int query(int p, const int ql, const int qr)
{
    if (ql <= t[p].l && t[p].r <= qr) return t[p].sum;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1, val = 0;
    if (ql <= mid) val += query(p << 1, ql, qr);
    if (mid < qr) val += query(p << 1 | 1, ql, qr);
    return val;
}
bool check(const int x)
{
    Now = x;
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int num = query(1, q[i].l, q[i].r);
        if (!q[i].opt)
            modify(1, q[i].l, q[i].r - num, 0),
            modify(1, q[i].r - num + 1, q[i].r, 1);
        else
            modify(1, q[i].l, q[i].l + num - 1, 1),
            modify(1, q[i].l + num, q[i].r, 0);
    }
    return (query(1, Q, Q) == 0);
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &q[i].opt, &q[i].l, &q[i].r);
    scanf("%d", &Q);
    std::sort(b + 1, b + n + 1);
    int l = 1, r = n, ans = n + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", b[ans]);
    return 0;
}