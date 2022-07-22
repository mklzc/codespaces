//url: https://www.luogu.com.cn/problem/P2398
#include <bits/stdc++.h>
const int N = 1e5 + 5;
using LL = long long;
int pr[N >> 1], cnt, mu[N], isp[N];
void mobius(int n)
{
    mu[1] = 1;
    for (int i = 2, t; i <= n; i++)
    {
        if (!isp[i]) mu[i] = -1, pr[++cnt] = i;
        for (int j = 1; j <= cnt && (t = pr[j] * i) <= n; j++)
        {
            isp[t] = 1;
            if (i % pr[j] == 0) break;
            mu[t] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) mu[i] += mu[i - 1];
}

int main()
{
    LL l = 1, r, ans = 0, n;
    scanf("%lld", &n);
    mobius(n);
    auto calc = [](LL x)->LL{
        LL l = 1, r, res = 0;
        while (l <= x) {
            r = x / (x / l);
            res += (mu[r] - mu[l - 1]) * (x / l) * (x / l);
            l = r + 1;
        }
        return res;
    };
    while (l <= n)
    {
        r = n / (n / l);
        ans += (r * (r + 1) / 2 - l * (l - 1) / 2) * calc(n / l);
        l = r + 1;
    }
    printf("%lld\n", ans);
    return 0;
}