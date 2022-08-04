#include <bits/stdc++.h>
const int Maxn = 3e6 + 5;
int a[Maxn];
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') { if (ch == '-') w = -1;ch = getchar();}
        while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
int main()
{
    // freopen("in", "r", stdin);
    int n, k, t;
    read(n, t, k);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    int ans = 0;
    for (int i = k; i <= k + t; i++)
    {
        // std::cout << "C(" << t << "," << i - k << ")" << ((t & (i - k)) == i - k) << "\n";
        int x = i;
        if (x % n != 0) x = x % n;
        if ((t & (i - k)) == i - k) ans ^= a[x]/* , std::cout << x << " " << a[x] << "\n" */;
    }
    printf("%d", ans);
    return 0;
}