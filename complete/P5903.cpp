#include <iostream>
#include <cstdio>
#include <vector>
const int Maxn = 5e5 + 10;
using ui = unsigned int;
using LL = long long;
ui s;
inline ui get(ui x)
{
	x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
	return s = x;
}
int n, q, rt, fa[Maxn];
int dep[Maxn], top[Maxn], son[Maxn], mdep[Maxn], f[Maxn][20], h[Maxn];
std::vector<int> G[Maxn], down[Maxn], up[Maxn];
void init(int x)
{
    mdep[x] = dep[x] = dep[fa[x]] + 1;
    f[x][0] = fa[x];
    for (int i = 1; i <= 19; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int y : G[x])
    {
        init(y);
        mdep[x] = std::max(mdep[y] + 1, mdep[x]);
        if (mdep[son[x]] < mdep[y]) son[x] = y;
    }
}
void dfs(int x, int t)
{
    top[x] = t;
    if (x == t)
    {
        for (int i = 0, node = x; i <= mdep[x] - dep[x]; i++)
            down[x].push_back(node), node = son[node];
        for (int i = 0, node = x; i <= mdep[x] - dep[x]; i++)
            up[x].push_back(node), node = fa[node];
    }
    if (son[x])
        dfs(son[x], t);
    for (int y : G[x])
        if (y != son[x]) dfs(y, y);
}
int query(int x, int k)
{
    // std::cerr << x << " " << k << " " << h[k] << "\n";
    if (k == 0) return x;
    x = f[x][h[k]];
    k -= (1 << h[k]) + dep[x] - dep[top[x]];
    x = top[x];
    // std::cerr << x << " " << k << "\n";
    return k >= 0 ? up[x][k] : down[x][-k];
}

int main()
{
    scanf("%d %d %u", &n, &q, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        if (!fa[i]) rt = i;
        else G[fa[i]].push_back(i);
        for (int j = 19; ~j; j--)
            if ((i >> j) & 1) { h[i] = j; break; }
    }
    init(rt);
    dfs(rt, rt);
    int ans = 0;
    LL Ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int x = ((get(s) ^ ans) % n) + 1;
        int k = (get(s) ^ ans) % dep[x];
        ans = query(x, k);
        Ans ^= 1ll * i * ans;
    }
    printf("%lld\n", Ans);
    return 0;
}