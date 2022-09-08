#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
int n, m, q, a[Maxn + 5], id[Maxn + 5];
int fa[Maxn << 1], rt[Maxn << 1], idx, tot;
struct Segment {
    int p, l, r, cnt;
} t[Maxn * 60];
int get(int x) { return x != fa[x] ? (fa[x] = get(fa[x])) : x; }
#define ls t[p].l
#define rs t[p].r
void pushup(int p) { t[p].cnt = t[t[p].l].cnt + t[t[p].r].cnt; }
void build(int &p, int l, int r, const int pos)
{
    if (!p) p = ++idx;
    if (l == r) return t[p].cnt = 1, void();
    int mid = (l + r) >> 1;
    if (pos <= mid) build(t[p].l, l, mid, pos);
    else build(t[p].r, mid + 1, r, pos);
    pushup(p);
}
int merge(int l, int r, int x, int y)
{
    if (!x || !y) return x | y;
    int z = ++idx;
    if (l == r)
        return t[z].cnt = t[x].cnt + t[y].cnt, z;
    int mid = (l + r) >> 1;
    t[z].l = merge(l, mid, t[x].l, t[y].l);
    t[z].r = merge(mid + 1, r, t[x].r, t[y].r);
    return pushup(z), z;
}
int query(int p, int l, int r, const int k)
{
    if (l == r) return l;
    int mid = (l + r) >> 1, sav = t[t[p].l].cnt;
    if (sav >= k) return query(t[p].l, l, mid, k);
    else return query(t[p].r, mid + 1, r, k - sav);
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), id[a[i]] = i;
    std::iota(fa + 1, fa + Maxn + Maxn, 1);
    for (int i = 1, u, v; i <= m; i++)
        scanf("%d %d", &u, &v), fa[get(u)] = get(v);
    for (int i = 1; i <= n; i++)
        build(rt[get(i)], 1, Maxn, a[i]);
    scanf("%d", &q);
    int x, y; char op;
    tot = n;
    while (q--)
    {
        std::cin >> op;
        scanf("%d %d", &x, &y);
        if (op == 'Q')
        {
            const int ans = query(rt[get(x)], 1, Maxn, y);
            printf("%d\n", ans != Maxn ? id[ans] : -1);
        }
        else
        {
            x = get(x), y = get(y);
            fa[x] = fa[y] = ++tot;
            rt[tot] = merge(1, Maxn, rt[x], rt[y]);
        }
    }
    return 0;
}