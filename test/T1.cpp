#include <bits/stdc++.h>
using LL = __int128;
const int Maxn = 3e6 + 5;
LL k, fac[Maxn];
int cnt;
void write(LL x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    scanf("%lld", &k);
    for (LL i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            fac[++cnt] = i;
            if (i * i != k) fac[++cnt] = k / i;
        }
    }
    std::sort(fac + 1, fac + cnt + 1);
    cnt--;
    for (int i = 1; i <= cnt; i++)
        if (fac[i] * fac[i] % k == 0)
            return write(fac[i]), 0;
    printf("-1");
    return 0;
}