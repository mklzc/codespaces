#include <bits/stdc++.h>
#define rep(_var, st, ed) for(int _var = st; _var <= ed; _var++)
using namespace std;
namespace io{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using io::read;
const int N = 2010;
int v[N], n;
struct Query {
    int x, w, v;
}t[N];
struct Node {
    int id;
    double val;
};std::vector<Node> G[N];
struct Edge {
    int l, r;
    double edge;
};std::vector<Edge> q;
long long ans = 0;
void dfs(int x, double now)
{
    if (v[x]) return;
    v[x] = 1;
    for (auto y : G[x])
    {
        if (y.val < now) continue;
        dfs(y.id, y.val);
    }
}
int find_min_edge()
{
    while (!q.empty())
    {
        auto y = q.back();
        if (v[y.l] || v[y.r]) {q.pop_back();continue;}
        if (!v[y.l] && !v[y.r]) {
            if (t[y.l].w < t[y.r].w) return y.l;
            else return y.r;
        }
    }
    return -1;
}
bool check() {
    rep(i, 1, n) if (!v[i]) return true;
    return false;
}
void brute()
{
    rep(i, 1, n)
        if (!v[i]) {
            int res = t[i].w;
            for (auto y : G[i])
                res = std::min(t[y.id].w, res);
            ans += res;
        }
}
void dg()
{
    if (!check()) return;
    int x = find_min_edge();
    if (x == -1) return void(brute());
    dfs(x, 0), ans += t[x].w;
    dg();
}
int main()
{
    read(n);
    rep(i, 1, n) read(t[i].x, t[i].v, t[i].w);
    std::sort(t + 1, t + n + 1, [&](Query a, Query b){return a.x < b.x;});

    auto add = [](int a, int b){
        double getTIME = fabs(double(t[b].x - t[a].x)) / fabs(double(t[a].v - t[b].v));
        G[a].push_back((Node){b, getTIME});
        G[b].push_back((Node){a, getTIME});
    };
    rep(i, 1, n) {
        rep(j, i + 1, n)
        {
            if (t[i].v > t[j].v)
            {
                add(i, j), add(j, i);
                q.push_back((Edge){i, j, G[i].back().val});
            }
        }
    }
    sort(q.begin(), q.end(), [&](Edge x, Edge y){return x.edge > y.edge;});
    dg();
    printf("%lld\n", ans);
    return 0;
}