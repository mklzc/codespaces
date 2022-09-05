#include <bits/stdc++.h>
using LL = long long;
const int Maxn = 1e5 + 10;
int T, Q, mod, n = Maxn - 5;
struct SegmentTree{
    int l, r;
    LL mul;
} t[Maxn << 2];
void pushup(int p){ t[p].mul = (t[p << 1].mul * t[p << 1 | 1].mul) % mod; }
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].mul = 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
void modify(int p, int pos, LL val)
{
    if (t[p].l == t[p].r) return void(t[p].mul = val);
    int mid = (t[p].l + t[p].r) >> 1;
    if (pos <= mid) modify(p << 1, pos, val);
    else modify(p << 1 | 1, pos, val);
    pushup(p);
}
void solve()
{
    scanf("%d %d", &Q, &mod);
    int op; LL m;
    build(1, 1, Q + 5);
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d %lld", &op, &m);
        if (op == 1) modify(1, i, m);
        else modify(1, m, 1);
        printf("%lld\n", t[1].mul % mod);
    }
}
int main()
{
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}