#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
int n, q[Maxn];
struct Node {
    int l, r;
} t[Maxn];
int sav[Maxn], ans = 0x3f3f3f3f;
void solve(int *f)
{
    memset(sav, 0, sizeof(sav));
    for (int i = 1; i <= n * 2; i++)
        if (i - f[i] > 0) sav[i - f[i]]++;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(sav[i], res);
    ans = std::min(ans, n - res);
}
bool check(int *f)
{
    static int cnt[Maxn];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        cnt[f[i]]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] > 1) return true;
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &t[i].l, &t[i].r);
    q[1] = 1;
    for (int i = 2; i <= n; i++)
        q[i] = (t[q[i - 1]].r != q[i - 2]) ? t[q[i - 1]].r : t[q[i - 1]].l;
    if (check(q)) return puts("-1"), 0;
    for (int i = n + 1; i <= n * 2; i++)
        q[i] = q[i - n];
    solve(q);
    std::reverse(q + 1, q + 2 * n + 1);
    solve(q);
    printf("%d\n", ans);
    return 0;
}