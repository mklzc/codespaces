// url: https://www.luogu.com.cn/problem/P4017
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, mod = 80112002;
vector<int> G[N];
struct Node
{
    int n, m, in[N], out[N];
    typedef long long LL;
    LL f[N];
    queue<int> q;
    void rai()
    {
        scanf("%d %d", &n, &m);
        while (m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            in[y]++, out[x]++;
        }
        for (int i = 1; i <= n; i++)
            if (!in[i]) q.push(i), f[i] = 1;
    }
    void run()
    {
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto y : G[x])
            {
                f[y] = (f[y] + f[x]) % mod, in[y]--;
                if (!in[y]) q.push(y);
            }
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++)
            if (!out[i]) ans = (ans + f[i]) % mod;
        printf("%lld\n", ans);
    }
}work;

int main()
{
    work.rai();
    work.run();
    return 0;
}