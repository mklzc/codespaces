//url: https://www.luogu.com.cn/problem/P3846
#include <bits/stdc++.h>
struct Node
{
    int a, b, p, t;
    std::unordered_map<int,int> hash;
    int bsgs()
    {
        int power = 1;
        for (int j = 0; j < t; j++)
        {
            hash[(1ll * b * power) % p] = j;
            power = (1ll * power * a) % p;
        }
        int res = power;
        for (int i = 1; i <= t; i++)
        {
            auto iter = hash.find(power);
            int val = iter != hash.end() ? iter->second : p;
            if (val != p)
                return i * t - val;
            power = (1ll * power * res) % p;
        }
        return -1;
    }
    void rai()
    {
        scanf("%d %d %d", &p, &a, &b);
        t = ceil(sqrt(p));
        int ans = bsgs();
        if (ans == -1)
            puts("no solution");
        else
            printf("%d\n", ans);
    }
}work;
int main()
{
    work.rai();
    return 0;
}