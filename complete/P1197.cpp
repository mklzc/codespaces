#include <bits/stdc++.h>
const int Maxn = 4e5 + 5;
int n, m;
struct Query {
    int id;
} q[Maxn << 1];
std::bitset<Maxn> vis;
std::vector<int> G[Maxn], sav[Maxn];
int fa[Maxn], ans[Maxn];
int get(int x)
{
    if (x != fa[x]) return fa[x] = get(fa[x]);
    return x;
}
void merge(int x, int y) { fa[get(x)] = get(y); }
bool check(int x, int y) { return get(x) == get(y); }
bool Find(int x, int y)
{
    int res = std::lower_bound(G[x].begin(), G[x].end(), y) - G[x].begin();
    return (res == y);
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d %d", &n, &m);
    std::iota(fa + 1, fa + Maxn, 1);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        sav[x].push_back(y);
        sav[y].push_back(x);
    }
    int k;
    scanf("%d", &k);
    
    for (int i = 1; i <= k; i++)
        scanf("%d", &q[i].id), vis[q[i].id] = 1;
    int part = n - k;
    for (int i = 0; i < n; i++)
    {
        for (int j : sav[i])
        {
            if (vis[i] || vis[j]) continue;
            // std::cout << i << " " << j << "\n";
            bool flag = false;
            G[i].push_back(j);
            G[j].push_back(i);
            if (!check(i, j)) flag = true;
            merge(i, j);
            if (flag && check(i, j)) part--;
        }
    }
    for (int i = k, id; i >= 1; i--)
    {
        ans[i] = part, id = q[i].id;
        part++;
        vis[id] = 0;
        for (int x : sav[id])
        {
            if (vis[x]) continue;
            bool flag = false;
            if (!check(id, x)) flag = true;
            merge(x, id);
            if (flag && check(id, x)) part--;
            G[x].push_back(id);
            G[id].push_back(x);
        }
    }
    printf("%d\n", part);
    for (int i = 1; i <= k; i++)
        printf("%d\n", ans[i]);
    return 0;
}