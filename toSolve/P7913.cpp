// url: https://www.luogu.com.cn/problem/P7913
#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
    x = 0;
    T w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    x = x * w;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args)
{
    read(t);
    read(args...);
}

const int N = 1e5 + 5;
struct Val
{
    int l, r;
    bool operator<(Val a) const
    {
        return r < a.r;
    }
};

struct Bridge
{
    int l, r;
    bool operator<(Bridge a) const
    {
        return l < a.l;
    }
};
set<Val> q;
struct Node
{
    static const int N = 1e5 + 5;
    Bridge dm[N], fr[N];
    Val dmx[N], frx[N];
    int n, m1, m2, dmnum[N], frnum[N];
    void RunDomestic()
    {
        int cnt = 0;
        q.insert(dmx[1]), cnt++;
        dmnum[cnt]++;
        for (int i = 2; i <= m1; i++)
        {
            auto x = q.begin();
            auto y = q.end();
            if (x->r < dmx[i].l)
            {
                q.erase(x);
                dmnum[cnt]++;
                q.insert(dmx[i]);
            }
            else if (cnt < n)
            {
                dmnum[++cnt]++;
                q.insert(dmx[i]);
            }
            else if (cnt == n && (--y)->r > dmx[i].r)
            {
                q.erase(y);
                q.insert(dmx[i]);
            }
        }
    }
    void RunForeign()
    {
        int cnt = 0;
        q.insert(frx[1]), cnt++;
        frnum[cnt]++;
        for (int i = 2; i <= m2; i++)
        {
            auto x = q.begin();
            auto y = q.end();
            if (x->r < frx[i].l)
            {
                q.erase(x);
                frnum[cnt]++;
                q.insert(frx[i]);
            }
            else if (cnt < n)
            {
                frnum[++cnt]++;
                q.insert(frx[i]);
            }
            else if (cnt == n && (--y)->r > frx[i].r)
            {
                q.erase(y);
                q.insert(frx[i]);
            }
        }
    }
    void Run()
    {
        RunDomestic();
        q.clear();
        RunForeign();
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += std::max(dmnum[i], frnum[i]);
        printf("%d\n", ans);
    }
    void Read()
    {
        read(n, m1, m2);
        for (int i = 1; i <= m1; i++)
            read(dm[i].l, dm[i].r);
        for (int i = 1; i <= m2; i++)
            read(fr[i].l, fr[i].r);
        sort(dm + 1, dm + m1 + 1);
        sort(fr + 1, fr + m2 + 1);
        for (int i = 1; i <= m1; i++)
            dmx[i].l = dm[i].l, dmx[i].r = dm[i].r;
        for (int i = 1; i <= m2; i++)
            frx[i].l = fr[i].l, frx[i].r = fr[i].r;
    }
} work;
int main()
{
    work.Read();
    work.Run();
    return 0;
}