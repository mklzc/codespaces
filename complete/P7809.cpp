// url: https://www.luogu.com.cn/problem/P7809
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, m, a[N], s[N], pre[N], suf[N], f[N][25], g[N];
inline char getChar()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
template <typename T>
inline void read(T &x)
{
    x = 0;
    char ch = getChar();
    while (ch < '0' || ch > '9')
        ch = getChar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getChar();
}
template <typename T, typename... Args>
inline void read(T &t, Args&... args)
{
    read(t);
    read(args...);
}
inline void write(int x)
{
    if (!x)
        putchar('0');
    char F[200];
    int tmp = x > 0 ? x : -x;
    if (x < 0)
        putchar('-');
    int cnt = 0;
    while (tmp > 0)
        F[cnt++] = tmp % 10 + '0', tmp /= 10;
    while (cnt > 0)
        putchar(F[--cnt]);
}
inline void raw()
{
    read(n, m);
    a[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        s[i] = s[i - 1] + a[i];
        g[i] = g[i - 1] + (a[i] && !a[i - 1]);
    }
    int sum = s[n];
    for (int i = 1; i <= n; i++)
    {
        suf[i] = sum - s[i];
        pre[i] = (i - 1) - s[i - 1];
        f[i][0] = suf[i] + pre[i] + 1;
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (i + (1 << j - 1) <= n)
                f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            else
                f[i][j] = f[i][j - 1];
    int op, l, r;
    while (m--)
    {
        read(op, l, r);
        int k = log2(r - l + 1);
        if (op == 1)
            write(max(f[l][k], f[r - (1 << k) + 1][k]) - pre[l] - suf[r]), putchar('\n');
        else
            if (g[r] - g[l] > 0) putchar('2'), putchar('\n');
            else putchar('1'), putchar('\n');
    }
}
int main() { return raw(), 0; }