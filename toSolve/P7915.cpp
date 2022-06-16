// url: https://www.luogu.com.cn/problem/P7915
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
template <typename T>
inline void read(T &x)
{
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
}
using std::string;
struct Node
{
    static const int N = 5e5 + 5;
    int n, a[N << 1];
    std::deque<int> p, q;
    char ans[N << 1];
    void Pop(string op)
    {
        if (op == "qf") q.pop_front();
        else if (op == "qb") q.pop_back();
        else if (op == "pf") p.pop_front();
        else p.pop_back();
    }
    bool check(int i, int qf, int qb, int pf, int pb)
    {
        if (qb == qf)
            return Pop("qb"), Pop("qf"), ans[i] = 'L', ans[2 * n + 1 - i] = 'L', true;
        if (pb == qf)
            return Pop("pb"), Pop("qf"), ans[i] = 'L', ans[2 * n + 1 - i] = 'R', true;
        if (qb == pf)
            return Pop("qb"), Pop("pf"), ans[i] = 'R', ans[2 * n + 1 - i] = 'L', true;
        if (pb == pf)
            return Pop("pb"), Pop("pf"), ans[i] = 'R', ans[2 * n + 1 - i] = 'R', true;
        return false;
    }
    bool Head()
    {
        ans[1] = 'L', ans[2 * n] = 'L';
        int pos;
        for (int i = 2; i <= n * 2; i++)
            if (a[i] == a[1]) pos = i;
        for (int i = 2; i <= n * 2; i++)
            if (i < pos) q.push_back(a[i]);
            else if (i > pos) p.push_front(a[i]);
        for (int i = 2; i <= n; i++)
            if (!check(i, q.front(), q.back(), p.front(), p.back()))
                return false;
        return true;
    }
    bool Tail()
    {
        ans[1] = 'R', ans[2 * n] = 'L';

        int pos;
        for (int i = 1; i <= 2 * n - 1; i++)
            if (a[i] == a[1]) pos = i;
        for (int i = 1; i <= n * 2 - 1; i++)
            if (i < pos) q.push_back(a[i]);
            else if (i > pos)
                p.push_front(a[i]);
        for (int i = 2; i <= n; i++)
            if (!check(i, q.front(), q.back(), p.front(), q.back()))
                return false;
        return true;
    }
    void run()
    {
        int sth = Head();
        string h = ans;
        std::cout << ans + 1 << '\n';
        q.clear(), p.clear();
        int stt = Tail();
        // string t = ans;
        // if (!stt && !sth) return void(puts("-1"));
        // printf("%s\n", h < t ? h.c_str() : t.c_str());
    }
    void rai()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++)
            scanf("%d", &a[i]);
        
    }
}work;
int main()
{
    freopen("in", "r", stdin);
    int T;
    read(T);
    while (T--)
    {
        work.rai();
        work.run();
    }
    return 0;
}