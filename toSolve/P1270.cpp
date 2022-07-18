#include <cstdio>
#include <iostream>
#include <vector>
int arrive_time;
int t[1005], cnt[1005], idx;
std::vector<int> G[1005];
void Read(int fa)
{
    scanf("%d %d", &t[++idx], &cnt[++idx]);
    std::cout << idx << " ";
    G[idx].push_back(fa);
    G[fa].push_back(idx);
    if (!cnt[idx]) Read(idx), Read(idx);
    else Read(idx);
}
int f[1005][1005], num[1005];
void dfs(int x, int fa)
{
    num[x] = cnt[x];
    for (int y : G[x])
    {
        if (y != fa) std::cout << y << " ";
        if (y == fa) continue;
        dfs(y, x);
    }
}
void dp(int x, int fa)
{
}
int main()
{
    freopen("in", "r", stdin);
    scanf("%d", &arrive_time);
    Read(0);
    return 0;
}