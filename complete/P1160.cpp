#include <bits/stdc++.h>
const int Maxn = 100010;
int n, pos[Maxn], vis[Maxn];
struct Node
{
    int l, r;
} t[Maxn];
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d", &n);
    int left = 1;
    for (int i = 2, k, p; i <= n; i++)
    {
        scanf("%d %d", &k, &p);
        if (!p)
        {
            if (k == left) left = i;
            t[t[k].l].r = i, t[i].l = t[k].l;
            t[k].l = i, t[i].r = k;
        }
        else
        {
            t[t[k].r].l = i, t[i].r = t[k].r;
            t[k].r = i, t[i].l = k;
        }
    }
    int sav = 0;
    for (int i = left; i; i = t[i].r)
        pos[i] = ++sav;
    int m;
    scanf("%d", &m);
    for (int i = 1, x; i <= m; i++)
        scanf("%d", &x), vis[x] = 1;
    std::vector<int> q;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) q.push_back(i);
    std::sort(q.begin(), q.end(), [&](int x, int y){return pos[x] < pos[y];});
    for (auto val : q)
        printf("%d ", val);
    return 0;
}