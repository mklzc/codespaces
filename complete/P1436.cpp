//url: https://www.luogu.com.cn/problem/P1436
#include <bits/stdc++.h>
#define rep(VAR, st, ed) for(int VAR = st; VAR <= ed; VAR++)
using namespace std;
int n, mp[10][10], s[10][10], f[17][10][10][10][10];
int main()
{
    scanf("%d", &n);
    auto sum = [&](int a, int b, int x, int y)->int{return s[x][y] - s[a - 1][y] - s[x][b - 1] + s[a - 1][b - 1];};
    auto dat = [&](int a, int b, int x, int y)->int{return sum(a, b, x, y) * sum(a, b, x, y);};
    auto init = [&](int i, int j){s[i][j] = mp[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];};
    auto Min = [&](int x, int y){return  x < y ? x : y;};
    rep(i, 1, 8) rep(j, 1, 8) scanf("%d", &mp[i][j]), init(i, j);
    rep(i, 1, 8) rep(j, 1, 8) rep(x, i, 8) rep(y, j, 8) f[0][i][j][x][y] = dat(i, j, x, y);
    rep(k, 1, n - 1)rep(i, 1, 8)rep(j, 1, 8)rep(x, i, 8)rep(y, j, 8){
        int Minn = 0x3f3f3f3f;
        rep(a, i, x - 1) Minn = Min(Minn, Min(f[k - 1][i][j][a][y] + f[0][a + 1][j][x][y], f[k - 1][a + 1][j][x][y] + f[0][i][j][a][y]));
        rep(b, j, y - 1) Minn = Min(Minn, Min(f[k - 1][i][j][x][b] + f[0][i][b + 1][x][y], f[k - 1][i][b + 1][x][y] + f[0][i][j][x][b]));
        f[k][i][j][x][y] = Minn;
    }
    printf("%d\n", f[n - 1][1][1][8][8]);
    return 0;
}