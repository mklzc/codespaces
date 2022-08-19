#include <bits/stdc++.h>
const int Maxn = 200010, INF = 0x3f3f3f3f;
int n, m, p[Maxn], val[Maxn];
int vis[Maxn][2];
struct Node {
    int l, r;
} t[Maxn];
struct Query {
    int id, hand;
} q[Maxn << 1];
std::pair<int, int> get(int x)
{
    if (x == p[x]) return {x, val[x]};
    auto rt = get(p[x]);
    val[x] += rt.second;
    p[x] = rt.first;
    return {p[x], val[x]};
}
void merge(int x, int y, int cl)
{
    auto dx = get(x), dy = get(y);
    if (dx.first == dy.first) return;
    if (dx.first == 1) std::swap(dx, dy);
    p[dx.first] = dy.first;
    val[dx.first] = (dy.first == 1) ? cl : 0;
}
void solve()
{
    for (int i = m; i >= 1; i--)
    {
        int x = q[i].id, y = (q[i].hand == 1) ? t[q[i].id].l : t[q[i].id].r;
        merge(x, y, i);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &t[i].l, &t[i].r);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &q[i].id, &q[i].hand);
        vis[q[i].id][q[i].hand - 1] = 1;
    }
    std::iota(p + 1, p + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i][0] && t[i].l != -1) merge(i, t[i].l, 0);
        if (!vis[i][1] && t[i].r != -1) merge(i, t[i].r, 0);
    }
    solve();
    for (int i = 1; i <= n; i++)
        printf("%d\n", get(i).second - 1);
    return 0;
}