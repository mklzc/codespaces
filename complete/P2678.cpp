#include <bits/stdc++.h>
const int Maxn = 5e4 + 2;
int L, n, m, d[Maxn], b[Maxn], v[Maxn];
int get_front(int x)
{
    int i = x - 1;
    while (v[i] && i >= 1) i--;
    return i;
}
int get_back(int x)
{
    int i = x + 1;
    while (i <= n && v[i]) i++;
    return i;
}
void modify(int x, int y, int val)
{
    b[x] += b[y] + val;
    v[y] = 1, b[y] = 0;
}
bool check(int x)
{
    for (int i = 1; i <= n; i++)
        b[i] = d[i] - d[i - 1] - x;
    b[n + 1] = L - d[n] - x;
    memset(v, 0, sizeof(v));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i]) continue;
        int fr = get_front(i);
        if (fr && b[i] < 0 && b[fr] < 0)
            modify(i, fr, x), cnt++;
    }
    if (cnt > m) return false;
    for (int i = 1; i <= n + 1; i++)
    {
        if (v[i]) continue;
        int fr = get_front(i), ba = get_back(i);
        if (b[i] < 0)
        {
            if (fr) modify(i, fr, x), cnt++;
            else modify(ba, i, x), cnt++;
        }
    }
    if (cnt > m) return false;
    for (int i = 1; i <= n; i++)
        if (b[i] < 0) return false;
    return true;
}
int main()
{
    scanf("%d %d %d", &L, &n, &m);
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
        Max = std::max(Max, d[i] - d[i - 1]);
    }
    Max = std::max(Max, L - d[n]);
    int l = 1, r = Max, ans = Max;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}