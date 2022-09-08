#include <bits/stdc++.h>
const int Maxn = 5e4 + 5, Maxm = 1e4 + 5;
int n, m;
std::vector<int> disc;
struct Seg {
    int l, r, Max;
} t[Maxn << 2];
struct Info {
    int year, rain;
} info[Maxn];
int Rain(int dyear) { return info[dyear].rain; }
int Year(int dyear) { return info[dyear].year; }
void pushup(int p) { t[p].Max = std::max(t[p << 1].Max, t[p << 1 | 1].Max); }
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].Max = 0;
    if (l == r)
        return void(t[p].Max = Rain(l));
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
const int INF = 0x3f3f3f3f;
int query(int p, const int ql, const int qr)
{
    if (ql > qr) return INF;
    if (ql <= t[p].l && t[p].r <= qr) return t[p].Max;
    int mid = (t[p].l + t[p].r) >> 1, val = -INF;
    if (ql <= mid) val = std::max(val, query(p << 1, ql, qr));
    if (mid < qr) val = std::max(val, query(p << 1 | 1, ql, qr));
    return val;
}
int Find(int x) { return (int)(std::lower_bound(disc.begin(), disc.end(), x) - disc.begin()); }
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &info[i].year, &info[i].rain),
        disc.push_back(info[i].year);
    build(1, 1, n);
    scanf("%d", &m);
    int x, y;
    while (m--)
    {
        scanf("%d %d", &y, &x);
        const int dx = Find(x) + 1, dy = Find(y) + 1;
        if (disc[dy - 1] == y && disc[dx - 1] != x)
        {
            
            const int Max = query(1, dy + 1, dx - 1);
            if (Max == INF) printf("maybe\n");
            else if (Max >= Rain(dy)) printf("false\n");
            else printf("maybe\n");
        }
        else if (disc[dy - 1] == y && disc[dx - 1] == x)
        {
            const int Max = query(1, dy + 1, dx - 1);
            if (Max == INF)
            {
                if (Rain(dx) > Rain(dy)) printf("false\n");
                else if (dx - dy + 1 < x - y + 1) printf("maybe\n");
                else printf("true\n");
            }
            else if (Rain(dx) > Rain(dy)) printf("false\n");
            else if (Max < Rain(dx) && x - y + 1 == dx - dy + 1) printf("true\n");
            else if (Max < Rain(dx) && x - y + 1 > dx - dy + 1) printf("maybe\n");
            else if (Max >= Rain(dx)) printf("false\n");
        }
        else if (disc[dy - 1] != y && disc[dx - 1] != x) printf("maybe\n");
        else if (disc[dy - 1] != y && disc[dx - 1] == x)
        {
            const int Max = query(1, dy, dx - 1);
            if (Max == INF) printf("maybe\n");
            else if (Rain(dx) <= Max) printf("false\n");
            else printf("maybe\n");
        }
    }
    return 0;
}