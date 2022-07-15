// brute
#define filein freopen("in", "r", stdin)
#include <cstdio>
using namespace std;
namespace io
{
    template <typename T>
    void read(T &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
    template <typename T>
    void write(T x)
    {
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + '0');
    }
};
using io::read;
using io::write;
using LL = long long;
class Main
{
private:
    static const int N = 15;
    int n, m, f[N], g[N];
    LL c[N];
    void mul(int *f, int *g, LL *c)
    {
        for (int k = 0; k <= n + m; k++)
            for (int i = 0; i <= k; i++)
                c[k] += 1ll * f[i] * g[k - i];
    }

public:
    void Rexe()
    {
        read(n);
        read(m);
        for (int i = 0; i <= n; i++)
            read(f[i]);
        for (int i = 0; i <= m; i++)
            read(g[i]);
        mul(f, g, c);
        for (int i = 0; i <= n + m; i++)
            write(c[i]), putchar(' ');
        putchar('\n');
    }

} FMain;
int main()
{
    filein;
    FMain.Rexe();
    return 0;
}