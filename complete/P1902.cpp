#include <bits/stdc++.h>
const int Maxn = 1010;
int n, m, map[Maxn][Maxn];
bool v[Maxn][Maxn];
std::queue<std::pair<int, int>> q;
bool check(int x)
{
    static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
    memset(v, 0, sizeof(v));
    while (!q.empty()) q.pop();
    for (int i = 1; i <= m; i++)
        if (map[1][i] < x) q.emplace(1, i);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (v[cur.first][cur.second]) continue;
        v[cur.first][cur.second] = 1;
        for (int i = 0; i < 4; i++)
        {
            int posx = cur.first + dx[i], posy =  cur.second + dy[i];
            if (map[posx][posy] > x || v[posx][posy] || posx > n || posx < 1 || posy > m || posy < 1) continue;
            if (posx == n) return true;
            q.emplace(posx, posy);
        }
    }
    return false;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int  i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
    int l = 0, r = 1000, ans = 1000;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}