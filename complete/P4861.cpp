/// url: https://www.luogu.com.cn/problem/P4861
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <iostream>
struct Node
{
    std::unordered_map<int, int> hash;
    int m, k, t;
    template <typename T>
    void out(T &x)
    {
        std::cout << x << " ";
    }
    template <typename T, typename... Args>
    void out(T &x, Args&...args)
    {
        out(x);
        out(args...);
        putchar('\n');
    }
    int qpow(int x, int y)
    {
        int res = 1;
        for (; y; y >>= 1)
        {
            if (y & 1)
                res = 1ll * res * x % m;
            x = 1ll * x * x % m;
        }
        return res;
    }
    int bsgs()
    {
        for (int j = 0; j < t; j++)
            hash[qpow(k, j)] = j;
        int power = qpow(k, t);
        for (int i = 1; i <= t; i++)
        {
            auto iter = hash.find(qpow(power, i));
            int val = iter != hash.end() ? iter->second : m;
            if (val != m)
                return i * t - val;
        }
        return -1;
    }
    void raw()
    {
        scanf("%d %d", &m, &k);
        t = ceil(sqrt(m));
        int ans = bsgs();
        if (ans == -1)
            puts("Let's go Blue Jays!");
        else printf("%d\n", ans);
    }
} work;
int main()
{
    work.raw();
    return 0;
}