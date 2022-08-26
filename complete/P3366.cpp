#include <bits/stdc++.h>
const int Maxm = 2e5 + 5, Maxn = 5010;
int n, m, ans;
struct Node
{
    int x, y, z;
} t[Maxm];
int fa[Maxn];
int get(int x) { return (fa[x] != x) ? (fa[x] = get(fa[x])) : x; }
void merge(int x, int y) { fa[get(x)] = get(y); }
bool check(int x, int y) { return get(x) == get(y); }
bool nos()
{
    std::iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= m; i++)
        merge(t[i].x, t[i].y);
    for (int i = 2; i <= n; i++)
        if (!check(i, i - 1)) return true;
    return false;
}
int main()
{
    scanf("%d %d", &n, &m);
    std::iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &t[i].x, &t[i].y, &t[i].z);
    std::sort(t + 1, t + m + 1, [&](Node a, Node b){ return a.z < b.z; });
    int scp = n - 1;
    for (int i = 1; i <= scp; i++)
    {
        if (check(t[i].x, t[i].y)) {scp++; continue;}
        merge(t[i].x, t[i].y);
        ans += t[i].z;
    }
    if (nos()) return puts("orz"), 0;
    printf("%d\n", ans);
    return 0;
}