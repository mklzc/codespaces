// url: https://www.luogu.com.cn/problem/P7913
#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
class Work
{
public:
    static const int N = 1e5 + 5;
    int n, m1, m2;
    struct Node
    {
        int l, r, id;
        bool operator<(const Node &x) const{
            return l < x.l;
        }
    } dm[N], fr[N];
    int dres[N], fres[N];
    typedef std::pair<int, int> pii;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Wait;
    std::priority_queue<int, std::vector<int>, std::greater<int>> Free;
    void calc(int m, Node *ptr, int *q);
    void Run(void);
    void Read()
    {
        scanf("%d %d %d", &n, &m1, &m2);
        for (int i = 1; i <= m1; i++)
            scanf("%d %d", &dm[i].l, &dm[i].r);
        for (int i = 1; i <= m2; i++)
            scanf("%d %d", &fr[i].l, &fr[i].r);
    }
    void Set()
    {
        while (!Wait.empty())
            Wait.pop();
        while (!Free.empty())
            Free.pop();
        for (int i = 1; i <= n; i++)
            Free.push(i);
    }
} work;
void Work::Run()
{
    calc(m1, dm, dres);
    calc(m2, fr, fres);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = std::max(ans, dres[i] + fres[n - i]);
        
    printf("%d\n", ans);
}
void Work::calc(int m, Node *ptr, int *res)
{
    std::sort(ptr + 1, ptr + m + 1);
    Set();
    for (int i = 1; i <= m; i++)
    {
        while (!Wait.empty() && Wait.top().first < ptr[i].l)
            Free.push(Wait.top().second),
            Wait.pop();
        if (!Free.empty())
        {
            ptr[i].id = Free.top();
            Wait.push({ptr[i].r, ptr[i].id}), Free.pop();
            res[ptr[i].id]++;
        }
    }
    for (int i = 1; i <= n; i++)
        res[i] += res[i - 1];
}
int main()
{
    work.Read();
    work.Run();
    return 0;
}