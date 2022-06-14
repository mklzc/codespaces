// url: https://www.luogu.com.cn/problem/P4748
#include <bits/stdc++.h>
using std::cout;
struct Node
{
    static const int N = 10000005;
    int sz[N], cnt[N], n;
    std::vector<int> ans;
    std::vector<int> G[N];
    void init(int x, int fa)
    {
        sz[x] = 1;
        for (int y : G[x])
            if (y != fa) init(y, x), sz[x] += sz[y];
        cnt[sz[x]]++;
    }
    bool check(int div)
    {
        int SIZE = n / div, sum = 0;
        for (int i = SIZE; i <= n; i += SIZE)
            sum = sum + cnt[i];
        return div == sum;
    }
    void run()
    {
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                if (i != 1 && check(i))
                    ans.push_back(i - 1);
                if (i != n / i && check(n / i))
                    ans.push_back(n / i - 1);
            }
        std::sort(ans.begin(), ans.end());
        for (int x : ans)
            printf("%d ", x);
    }
    void rai()
    {
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
        scanf("%d", &n);
        int a, b;
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        init(1, 0);
    }
} work;
int main()
{
    work.rai();
    work.run();
    return 0;
}
