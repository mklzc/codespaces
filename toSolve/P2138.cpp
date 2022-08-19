#include <bits/stdc++.h>
const int Maxn = 105;
char a[Maxn], b[Maxn];
int f[Maxn][Maxn];
int main()
{
    std::cin >> a >> b;
    if (strlen(a) > strlen(b))
        std::swap(a, b);
    int la = strlen(a), lb = strlen(b);
    for (int i = 0; i < la; i++)
        for (int j = 0; j < lb; j++)
        {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
        }
    int ans = 0;
    std::cout << f[la - 1][lb - 1] << "\n";
    if (!f[la - 1][lb - 1])
    {
        while (lb)
        {
            ans++;
            if (lb <= la) break;
            lb = std::ceil(double(lb) / 2.0);
        }
    }
    else
    {
        while (lb)
        {
            ans ++;
            if (lb <= f[la - 1][lb - 1])
                break;
            lb = std::ceil(double(lb) / 2.0);
            std::cout << "lb: " << lb << "\n";
        }
    }
    std::cout << ans << "\n";
    return 0;
}