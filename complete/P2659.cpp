#include <bits/stdc++.h>
template<typename T>
inline void read(T &x)
{
    x = 0;
    T w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w = -1;
        ch=getchar();
    }
    while(ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    x = x * w;
}
const int Maxn = 2000010;
using LL = long long;
LL ans = 0;
int n, a[Maxn], R[Maxn], L[Maxn];
int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    std::stack<int> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[q.top()] > a[i])
            R[q.top()] = i, q.pop();
        q.push(i);
    }
    while (!q.empty()) q.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!q.empty() && a[q.top()] > a[i])
            L[q.top()] = i, q.pop();
        q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int l = !L[i] ? 1 : L[i] + 1, r = !R[i] ? n : R[i] - 1;
        ans = std::max(1ll * (r - l + 1) * a[i], ans);
    }
    printf("%lld\n", ans);
    return 0;
}