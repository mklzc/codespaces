// url: https://www.luogu.com.cn/problem/P4810
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
}
const int N = 3e5 + 5;
int n, st[N], d[N], f[N][20], t;
inline int lca(int x, int y)
{
    if (d[x] > d[y]) swap(x, y);
    for (int i = t; i >= 0; i--)
        if (d[x] <= d[f[y][i]]) y = f[y][i];
    if (x == y) return x;
    for (int i = t; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
void write(int x)
{
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
inline void raw()
{
    read(n);
    t = log2(n) + 1;
    int v, w;
    for (int i = 1; i <= n; i++)
    {
        char ch = getchar();
        read(v);
        v = st[v];
        if (ch == 'a')
        {
            st[i] = i, f[i][0] = v, d[i] = d[v] + 1;
            for (int j = 1; j <= t; j++)
                f[i][j] = f[f[i][j - 1]][j - 1];
        }
        else if (ch == 'b')
            write(v), putchar('\n'), st[i] = f[v][0];
        else
            read(w), write(d[lca(st[w], v)]), putchar('\n'), st[i] = v;
    }
}
int main() { return raw(), 0; }