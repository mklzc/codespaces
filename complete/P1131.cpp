#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') { if (ch == '-') w = -1;ch = getchar();}
        while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
using LL = long long;
const int N = 500010;
int n, s;
LL f[N], path[N];
struct Node {
    int id;
    LL cost;
}; std::vector<Node> G[N];
void dp(int x, int fa)
{
    LL Max = 0;
    for (auto son : G[x])
    {
        if (son.id == fa) continue;
        dp(son.id, x);
        f[x] += f[son.id], Max = std::max(Max, path[son.id] + son.cost);
    }
    path[x] = Max;
    for (auto son : G[x])
        if (son.id != fa) f[x] += Max - path[son.id] - son.cost;
}
int main()
{
    read(n, s);
    rep(i, 1, n - 1)
    {
        int u, v; LL t;
        read(u, v, t);
        G[u].push_back((Node){v, t});
        G[v].push_back((Node){u, t});
    }
    dp(s, 0);
    printf("%lld\n", f[s]);
	return 0;
}