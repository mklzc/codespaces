#include <bits/stdc++.h>

int main()
{
    int n, a, b, c, d;
    scanf("%d", &n);
    auto check = [](int a, int b, int k)->bool{
        return ceil(1.0 * a / k) <= floor(1.0 * b / k);
    };
    while (n--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int ans = 1;
        for (int k = 1, r; k <= std::min(b, d); k = r + 1)
        {
            r = std::min(b / (b / k), d / (d / k));
            if (check(a, b, r) && check(c, d, r))
                ans = r;
        }
        printf("%d\n", ans);
    }
    return 0;
}