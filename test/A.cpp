#include <bits/stdc++.h>
const int Maxn = 1e5 + 5, MaxQ = 1e6 + 5;
int n, m, Q, a[MaxQ];
bool ans[1 << 11][Maxn];
std::vector<int> dis;
struct Query {
    int opt, l, r, val;
} q[MaxQ];
struct Seg {
    int l, r, val, tag;
} t[MaxQ << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) { t[p].val = t[ls].val | t[rs].val; }
void pushdown(int p)
{
    if (t[p].tag == -1) return;
    t[ls].tag = t[p].tag, t[rs].tag = t[p].tag;
    t[ls].val = t[p].tag, t[rs].val = t[p].tag;
    t[p].tag = -1;
}
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].tag = -1;
    if (l == r)
        return void(t[p].val = (1 << a[l]));
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(p);
}
void modify(int p, const int ql, const int qr, const int x)
{
    if (ql <= t[p].l && t[p].r <= qr)
        return t[p].val = x, void(t[p].tag = x);
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (ql <= mid) modify(ls, ql, qr, x);
    if (mid < qr) modify(rs, ql, qr, x);
    pushup(p);
}
int query(int p, const int ql, const int qr)
{
    if (ql <= t[p].l && t[p].r <= qr) return t[p].val;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1, state = 0;
    if (ql <= mid) state |= query(ls, ql, qr);
    if (mid < qr) state |= query(rs, ql, qr);
    return state;
}
void init()
{
    const int diss = dis.size();
    for (int state = 0; state < (1 << diss); ++state)
    {
        ans[state][0] = true;
        for (int i = 0; i < diss; ++i)
            if ((state >> i) & 1)
            {
                for (int j = dis[i]; j <= m; ++j)
                    ans[state][j] |= ans[state][j - dis[i]];
            }
    }
    auto Find = [](int x) ->int{
        return std::lower_bound(dis.begin(), dis.end(), x) - dis.begin();
    };
    for (int i = 1; i <= n; i++)
        a[i] = Find(a[i]);
    for (int i = 1; i <= Q; i++)
        if (q[i].opt == 1) q[i].val = Find(q[i].val);
    build(1, 1, n);
}
int main()
{
    scanf("%d %d %d", &n, &m, &Q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dis.push_back(a[i]);
    }
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d %d %d %d", &q[i].opt, &q[i].l, &q[i].r, &q[i].val);
        if(q[i].opt == 1) dis.push_back(q[i].val);
    }
    std::sort(dis.begin(), dis.end());
    dis.erase(std::unique(dis.begin(), dis.end()), dis.end());
    init();
    for (int i = 1; i <= Q; i++)
    {
        if (q[i].opt == 1) modify(1, q[i].l, q[i].r, 1 << q[i].val);
        else printf(ans[query(1, q[i].l, q[i].r)][q[i].val] ? "Yes\n" : "No\n");
    }
    return 0;
}