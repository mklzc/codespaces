#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
using LL = long long;
int n;
LL a[Maxn];
std::map<long long, int> q;
struct Node
{
    int l, r;
    LL mx;
} t[Maxn << 2];
int idx;
void pushup(int p) { t[p].mx = std::max(t[t[p].l].mx, t[t[p].r].mx); }
int build(int l, int r)
{
    int p = ++idx;
    if (l == r)
    {
        t[p].mx = a[l];
        return p;
    }
    int mid = (l + r) >> 1;
    t[p].l = build(l, mid);
    t[p].r = build(mid + 1, r);
    pushup(p);
    return p;
}
int st, ed;
LL query(int p, int l, int r)
{
    if (st <= l && r <= ed)
        return t[p].mx;
    int mid = (l + r) >> 1;
    LL val = 0;
    if (st <= mid)
        val = std::max(val, query(t[p].l, l, mid));
    if (ed > mid)
        val = std::max(val, query(t[p].r, mid + 1, r));
    return val;
}
LL Query(int l, int r)
{
    st = l, ed = r;
    return query(1, 1, n);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]),
        q[a[i]] = i;
    build(1, n);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        // printf("%lld\n", Query(x, y));
        printf("%lld\n", q[Query(x, y)]);
    }
    return 0;
}