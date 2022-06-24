#include <cstdio>
#define filein freopen("in", "r", stdin)
#define filout freopen("out", "w", stdout)
typedef long long LL;
const int N = 250003;
class IO
{
public:
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args &...args)
    {
        read(x);
        read(args...);
    }
    template <typename T>
    inline void write(T x)
    {
        char F[200];
        T tmp = x > 0 ? x : -x;
        if (x < 0)
            putchar('-');
        int cnt = 0;
        while (tmp > 0)
            F[cnt++] = tmp % 10 + '0', tmp /= 10;
        while (cnt > 0)
            putchar(F[--cnt]);
    }
} io;
struct City
{
    int For;
    LL army;
} a[N];
int n, q, c;

int main()
{
    filein;
    io.read(n, q, c);
    for (int i = 1; i <= n; i++)
        io.read(a[i].army);
    for (int i = 1; i <= n; i++)
        io.read(a[i].For);
    int op, l, r;
    while (q--)
    {
        io.read(op, l, r);
        if (op == 1)
        {
            int x, y;
            io.read(x, y);
            for (int i = l; i <= r; i++)
                if (a[i].For == x)
                    a[i].For = y;
        }
        else if (op == 2)
        {
            int x, v;
            io.read(x, v);
            for (int i = l; i <= r; i++)
                if (a[i].For == x)
                    a[i].army += v;
        }
        else
        {
            LL ans = 0;
            for (int i = l; i <= r; i++)
                ans += a[i].army;
            io.write(ans);
            putchar('\n');
        }
    }
    return 0;
}