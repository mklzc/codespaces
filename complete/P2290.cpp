#include <bits/stdc++.h>
using LL = long long;
const int N = 200;
int n, pr[N], c[N], cnt;
void split(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int k = 1;
            while (pr[k] < i) k++;
            while (x % i == 0) x /= i, c[k]--;
        }
    }
    if (x > 1)
    {
        int k = 1;
        while (pr[k] < x) k++;
        c[k]--;
    }
}
void sie(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            int k = 1;
            while (pr[k] < i) k++;
            if (pr[k] != i)
            {
                pr[++cnt] = i;
                while (x % i == 0) x /= i, c[cnt]++;
            }
            else
                while (x % i == 0) x /= i, c[k]++;
        }
    if (x > 1)
    {
        int k = 1;
        while (pr[k] < x) k++;
        if (pr[k] != x) pr[++cnt] = x, c[cnt] = 1;
        else c[k]++;
    } 
}
int main()
{
    memset(pr, 0x3f, sizeof(pr));
    scanf("%d", &n);
    int d, tot = 0;
    if (n == 1)
    {
        scanf("%d", &d);
        if (d == 0) return puts("1"), 0;
        else return puts("0"), 0;
    }   
    for (int i = 2; i <= n - 2; i++)
        sie(i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d);
        if (d < 1 || d > n) return puts("0"), 0;
        tot += d - 1;
        for (int i = 2; i <= d - 1; i++) split(d - 1);
    }
    if (tot != n - 2) return puts("0"), 0;
    LL ans = 1;
    for (int i = 1; i <= cnt; i++) while (c[i]--) ans *= pr[i];
    std::cout << ans << "\n";
    return 0;
}