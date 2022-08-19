#include <bits/stdc++.h>   
int n;
std::set<int> s;
int main()
{
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        auto sav = s.lower_bound(x);
        int res1 = std::abs(*sav - x), res2;
        if (sav != s.begin()) sav--;
        res2 = std::abs(*sav - x);
        if (i != 1) ans += std::min(res1, res2);
        else ans += x;
        s.insert(x);
    }
    printf("%d\n", ans);
    return 0;
}