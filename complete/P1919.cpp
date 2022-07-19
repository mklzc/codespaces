#include <bits/stdc++.h>
#define rep(VAR, st, ed) for (int VAR = st; VAR <= ed; VAR++)
const int N = 2200000;
const double pi = acos(-1);
struct Plural
{
    double x, y;
    Plural(double _x = 0, double _y = 0) { x = _x, y = _y; }
    Plural operator+(Plural a) const { return Plural(x + a.x, y + a.y); }
    Plural operator-(Plural a) const { return Plural(x - a.x, y - a.y); }
    Plural operator*(Plural a) const { return Plural(x * a.x - y * a.y, x * a.y + y * a.x); }
} f[N], g[N];
int tr[N], ans[N], n, m;
void fft(Plural *f, double st)
{
    rep(i, 0, n) if (i < tr[i]) std::swap(f[i], f[tr[i]]);
    for (int p = 2; p <= n; p <<= 1)
    {
        Plural e(cos(2 * pi / p), st * sin(2 * pi / p));
        int len = p >> 1;
        for (int k = 0; k < n; k += p)
        {
            Plural buf(1, 0);
            rep(l, k, k + len - 1)
            {
                Plural res = buf * f[l + len];
                f[l + len] = f[l] - res;
                f[l] = f[l] + res;
                buf = buf * e;
            }
        }
    }
}
int main()
{
    std::string s, t;
    std::cin >> s >> t;
    n = s.size(), m = t.size();
    rep(i, 0, n - 1) f[i].x = s[i] - '0';
    rep(i, 0, m - 1) g[i].x = t[i] - '0';
    for (m += n, n = 1; n <= m; n <<= 1)
        continue;
    std::reverse(f, f + n);
    std::reverse(g, g + m);

    rep(i, 0, n - 1)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
    fft(f, 1), fft(g, 1);
    rep(i, 0, n)
        f[i] = f[i] * g[i];
    fft(f, -1);
    tr[m + 1] = 0;
    for (int i = 0; i <= m; i++)
    {
        if (i)
            tr[i] = tr[i - 1] + int(f[i].x / n + 0.5);
        else
            tr[i] = int(f[i].x / n + 0.5);
        ans[i] = tr[i] % 10;
        tr[i] /= 10;
    }
    while (!ans[m] && m > 0)
        m--;
    for (int i = m; i >= 0; i--)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}