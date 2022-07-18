// url: https://www.luogu.com.cn/problem/P3803
#include <bits/stdc++.h>
const int N = int(1350000) << 1;
const double pi = acos(-1);
struct Node
{
    double x, y;
    Node(double _x = 0, double _y = 0) { x = _x, y = _y; }
    Node operator+(Node const &B) const {
        return Node(x + B.x, y + B.y);
    }
    Node operator-(Node const &B) const {
        return Node(x - B.x, y - B.y);
    }
    Node operator*(Node const &B) const {
        return Node(x * B.x - y * B.y, x * B.y + y * B.x);
    }
} f[N], g[N], sav[N];
int n, m, tr[N];
void fft(Node *f, double st)
{
    for (int i = 0; i <= n; i++)
        if (i < tr[i]) std::swap(f[i], f[tr[i]]);
    for (int p = 2; p <= n; p <<= 1)
    {
        Node e(cos(2*pi/p), st*sin(2*pi/p));
        int len = p >> 1;
        for (int k = 0; k < n; k += p)
        {
            Node buf(1, 0);
            for (int l = k; l < k + len; l++)
            {
                Node tmp = buf * f[len + l];
                f[len + l] = f[l] - tmp;
                f[l] = f[l] + tmp;
                buf = buf * e;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%lf", &f[i].x);
    for (int i = 0; i <= m; i++)
        scanf("%lf", &g[i].x);
    for (m += n, n = 1; n <= m; n <<= 1);
	for (int i = 0; i < n; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
    fft(f, 1.0), fft(g, 1.0);
    for (int i = 0; i < n; i++)
        f[i] = f[i] * g[i];
    fft(f, -1);
    for (int i = 0; i <= m; ++i)
        printf("%d ", (int)(f[i].x / n + 0.49));
    puts("");
    return 0;
}