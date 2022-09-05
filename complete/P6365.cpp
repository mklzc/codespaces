#include <bits/stdc++.h>
int n;
std::map<int, int> mp;
std::vector<int> q;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        mp[a]++, q.push_back(a);
        if ((a ^ b) != a) mp[a ^ b]++, q.push_back(a ^ b);
    }
    int Max = 0, pos = 0;
    std::sort(q.begin(), q.end());
    for (int x : q)
        if (Max < mp[x])
            Max = mp[x], pos = x;
        
    printf("%d\n", pos);
    return 0;
}