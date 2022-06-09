//url: https://www.luogu.com.cn/problem/P2261
#include <bits/stdc++.h>
using namespace std;
inline int raw()
{
    typedef long long LL;
    LL n, k, i = 1, r, ans = 0;
    scanf("%lld %lld", &n, &k);
    while (i <= n && (k / i))
    {
        r = min(k / (k / i), n);
        LL pre = (i + r) * (r - i + 1) / 2;
        ans += pre * (k / i);
        i = r + 1;
    }
    printf("%lld\n", n * k - ans);
    return 0;
}
int main() {return raw();}