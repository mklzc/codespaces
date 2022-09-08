#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
using LL = long long;
int n, m;
LL t[Maxn << 2], laz[Maxn << 2], a;
inline void pushup(int p, int l, int r) { t[p] = t[p << 1] + t[p << 1 | 1] + (r - l + 1) * laz[p]; }
void build(int p, int l, int r)
{
    if (l == r)
    {
        scanf("%d", &a);
        return t[p] = a, void();
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p, l, r);
}
void modify(int p, int l, int r, const int ql, const int qr, const LL val)
{
    if (ql <= l && r <= qr)
        return t[p] += (r - l + 1) * val, laz[p] += val, void();
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(p << 1, l, mid, ql, qr, val);
    if (mid < qr)
        modify(p << 1 | 1, mid + 1, r, ql, qr, val);
    pushup(p, l, r);
}
LL query(int p, int l, int r, const int ql, const int qr)
{
    if (ql <= l && r <= qr) return t[p];
    int mid = (l + r) >> 1;
    LL res = laz[p] * (std::min(r, qr) - std::max(ql, l) + 1);
    if (res < 0) res = 0;
    if (ql <= mid) res += query(p << 1, l, mid, ql, qr);
    if (mid < qr) res += query(p << 1 | 1, mid + 1, r, ql, qr);
    return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    int op, l, r; LL k;
    build(1, 1, n);
    while (m--)
    {
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1)
        {
            scanf("%lld", &k);
            modify(1, 1, n, l, r, k);
        }
        else printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}