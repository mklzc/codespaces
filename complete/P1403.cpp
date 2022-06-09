// url: https://www.luogu.com.cn/problem/P1403
#include <bits/stdc++.h>
using namespace std;
int raw()
{
    int i = 1, n;
    scanf ("%d", &n);
    typedef long long LL;
    LL ans = 0;
    while (i <= n)
    {
        int brd = n / (n / i);
        ans += 1ll * (brd - i + 1) * (n / i);
        i = brd + 1; 
    }
    printf("%lld\n", ans);
    return 0;
}
int main() { return raw(); }