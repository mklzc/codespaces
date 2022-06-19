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
const int N = 5e5 + 5;
std::deque<int> p, q;
char ans[N << 1];
int n, a[N << 1];
struct Node
{
    void Pop(string op)
    {
        if (op == "qf")
            q.pop_front();
        else if (op == "qb")
            q.pop_back();
        else if (op == "pf")
            p.pop_front();
        else
            p.pop_back();
    }
    bool check(int i, int qf, int qb, int pf, int pb)
    {
        if (qf == qb && q.size() > 1)
            return Pop("qf"), Pop("qb"), ans[i] = 'L', ans[2 * n + 1 - i] = 'L', true;
        if (qf == pb) 
            return Pop("qf"), Pop("pb"), ans[i] = 'L', ans[2 * n + 1 - i] = 'R', true;
        if (pf == qb)
            return Pop("pf"), Pop("qb"), ans[i] = 'R', ans[2 * n + 1 - i] = 'L', true;
        if (pf == pb && p.size() > 1)
            return Pop("pf"), Pop("pb"), ans[i] = 'R', ans[2 * n + 1 - i] = 'R', true;
        return false;
    }
    bool Palindrome()
    {
        for (int i = 1; i <= n; i++)
            if (a[i] != a[2 * n - i + 1])
                return false;
        return true;
    }
    bool Head()
    {
        ans[1] = 'L', ans[2 * n] = 'L';
        int pos;
        for (int i = 2; i <= n * 2; i++)
            if (a[i] == a[1])
                pos = i;
        for (int i = 2; i <= n * 2; i++)
            if (i < pos)
                q.push_back(a[i]);
            else if (i > pos)
                p.push_front(a[i]);
        if (!p.size())
        {
            for (int i = 1; i <= n * 2; i++)
                ans[i] = 'L';
            return Palindrome();
        }
        for (int i = 2; i <= n; i++)
        {
            int qf, qb, pf, pb;
            if (!q.size()) qf = 0, qb = 0;
            else qf = q.front(), qb = q.back();
            if (!p.size()) pf = 0, pb = 0;
            else pf = p.front(), pb = p.back();
            if (!check(i, qf, qb, pf, pb))
                return false;
        }
        return true;
    }
    bool Tail()
    {
        ans[1] = 'R', ans[2 * n] = 'L';
        int pos;
        for (int i = 1; i <= n * 2 - 1; i++)
            if (a[i] == a[n * 2])
                pos = i;
        for (int i = 1; i <= n * 2 - 1; i++)
            if (i < pos)
                q.push_back(a[i]);
            else if (i > pos)
                p.push_front(a[i]);
        if (!q.size())
        {
            for (int i = 1; i <= n * 2; i++)
                ans[i] = 'R';
            return Palindrome();
        }
        for (int i = 2; i <= n; i++)
        {
            int qf, qb, pf, pb;
            if (!q.size()) qf = 0, qb = 0;
            else qf = q.front(), qb = q.back();
            if (!p.size()) pf = 0, pb = 0;
            else pf = p.front(), pb = p.back();
            if (!check(i, qf, qb, pf, pb))
                return false;
        }
        return true;
    }
    void run()
    {
        bool stt = false, sth = false;
        q.clear(), p.clear(), memset(ans, '\0', sizeof(ans));
        sth = Head();
        if (sth)
            return void(std::cout << ans + 1 << "\n");
        q.clear(), p.clear(), memset(ans, '\0', sizeof(ans));
        stt = Tail();
        if (!stt && !sth)
            return void(puts("-1"));
        std::cout << ans + 1 << "\n";
    }
    void rai()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++)
            scanf("%d", &a[i]);
    }
} work;
int main()
{
    int T;
    read(T);
    while (T--)
    {
        work.rai();
        work.run();
    }
    return 0;
}