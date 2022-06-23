#include <bits/stdc++.h>
#define filein freopen("in", "r", stdin)
#define filout freopen("out", "w", stdout)
class IO
{
public:
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
    inline void read(T &x, Args &...args)
    {
        read(x);
        read(args...);
    }
    template <typename T>
    inline void write(T x)
    {
        char F[200];
        T tmp = x > 0 ? x : -x;
        if (x < 0)
            putchar('-');
        int cnt = 0;
        while (tmp > 0)
            F[cnt++] = tmp % 10 + '0', tmp /= 10;
        while (cnt > 0)
            putchar(F[--cnt]);
    }
} io;
const int N = 4e5 + 5;
class Main
{
public:
    int n, m, q;
    unsigned long long ans = 0;
    std::bitset<N> vis;
    struct Node
    {
        int x, y, op, id;
    } Q[N];
    void Read(void);
    void Run(void);
} work;
class Operation
{
public:
    int fa[N], GC_TIME[N], LAST_GC_TIME;
    std::vector<int> G[N];
    int get(int x)
    {
        if (fa[x] != x)
            return fa[x] = get(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) { fa[get(x)] = get(y); }
    bool check(int x, int y) { return get(x) == get(y); }
    void add(int x, int y) {G[x].push_back(y), G[y].push_back(x);}
    void calc(int x)
    {
        if (!LAST_GC_TIME) return;
        // std::cout << "time: " << x << " " << LAST_GC_TIME << "\n";
        GC_TIME[x] = LAST_GC_TIME;
        for (int y : G[x])
            if (!GC_TIME[y]) calc(y);
    }
    void INIT_FIND_SET()
    {
        for (int i = 1; i <= work.n; i++)
            fa[i] = i;
    }
} OP;
void Main::Read()
{
    io.read(n, m, q);
    for (int i = 1; i <= m; i++)
        io.read(Q[i].x, Q[i].y);
    char op[10];
    for (int i = 1; i <= q; i++)
    {
        scanf("%s", op);
        if (op[0] == 'D')
            io.read(Q[i].id), Q[i].op = 0, vis[Q[i].id] = 1;
        else
            Q[i].op = 1;
    }
}
void Main::Run()
{
    OP.INIT_FIND_SET();
    for (int i = 1; i <= m; i++)
        if (!vis[i] && !OP.check(Q[i].x, Q[i].y))
            OP.add(Q[i].x, Q[i].y), OP.merge(Q[i].x, Q[i].y);
    OP.LAST_GC_TIME = 0;
    for (int i = q; i >= 1; i--)
    {
        if (!Q[i].op)
        {
            int u = Q[Q[i].id].x, v = Q[Q[i].id].y;
            if (OP.check(u, v)) continue;
            if (OP.check(1, u) && !OP.check(1, v))
                OP.calc(v);
            else if (OP.check(1, v) && !OP.check(1, u))
                OP.calc(u);
            OP.merge(u, v);
            OP.add(u, v);
        }
        else
            OP.LAST_GC_TIME = i;
    }
    OP.INIT_FIND_SET();
    for (int i = 1; i <= m; i++)
        OP.merge(Q[i].x, Q[i].y);
    for (int i = 1; i <= n; i++)
    {
        if (OP.GC_TIME[i] == 0)
            OP.GC_TIME[i] = q + 1;
        if (!OP.check(i, 1))
            OP.GC_TIME[i] = OP.LAST_GC_TIME;
    }
    for (int i = 1; i <= n; i++)
    {
        unsigned long long a;
        io.read(a);
        ans += OP.GC_TIME[i] * a;
    }
    io.write(ans);
}
int main()
{
    work.Read();
    work.Run();
    return 0;
}