// url: https://www.luogu.com.cn/problem/P6583
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
typedef long long LL;
LL n, k[N];
int cnt;
inline void init()
{
    for (LL i = 1; i <= n; i *= 2)
        for (LL j = i; j <= n; j *= 5)
            k[++cnt] = j;
}
inline int raw()
{
    scanf("%lld", &n);
    init();
    sort(k + 1, k + cnt + 1);
    LL ans = 0;
    for (LL i = 1, r; i <= n && (n / i); i = r + 1)
    {
        r = n / (n / i);
        while (cnt && k[cnt] > (n / i))
            cnt--;
        LL len = (r - i + 1) - (r / 2 - (i - 1) / 2) - (r / 5 - (i - 1) / 5) + (r / 10 - (i - 1) / 10);
        ans += len * (n / i) * cnt;
    }
    printf("%lld\n", ans);
    return 0;
}
int main() { return raw(); }