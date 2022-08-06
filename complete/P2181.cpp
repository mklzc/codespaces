#include <bits/stdc++.h>
using LL = unsigned long long;
bool st[5];
LL mul(LL a, LL b)
{
    LL s = a * b;
    for (int i = 2; i <= 4; i++)
        if (s % i == 0 && !st[i]) s /= i, st[i] = 1;
    return s;
}
int main()
{
    LL n;
    scanf("%llu", &n);
    LL ans = mul(n, n - 1);
    ans = mul(ans, n - 2) ;
    ans = mul(ans, n - 3);
    printf("%llu\n", ans);
    return 0;
}