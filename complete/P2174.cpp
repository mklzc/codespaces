// url: https://www.luogu.com.cn/problem/P2174
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#define filein freopen("in", "r", stdin)
#define fileout freopen("out", "w", stdout)
using LL = long long;
namespace io{
    template<typename T>
    void read(T &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
    }
    void write(int x)
    {
        if(x<0)
            putchar('-'), x = -x;
        if(x>9)
            write(x / 10);
        putchar(x % 10 + '0');
        return;
    }
};
using io::read;
using io::write;
class Main
{
public:
    static const int mod = 317847191;
    int n, m, mul = 1;
    std::multiset<int> q;
    inline void Read()
    {
        read(n);
        read(m);
        while (n--)
        {
            int a;
            read(a);
            mul = 1ll * mul * a % mod;
            q.insert(a);
        }
    }
    inline void Run();
    inline int qpow(int x, int y);
    void exgcd(int a, int b, int &x, int &y)
    {
        if (b == 0)
            return void(x = 1), void(y = 0);
        exgcd(b, a % b, x, y);
        int z = x;
        x = y, y = z - (a / b) * y;
    }
    inline int inv(int k)
    {
        int x, y;
        exgcd(k, mod, x, y);
        return x;
    }
}FMain;
inline int Main::qpow(int x, int y)
{
    LL res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
    }
    return res;
}
inline void Main::Run()
{
    int x, y;
    char op;
    while (m--)
    {
        op = '\0';
        while(op != 'D' && op != 'B' && op != 'S' && op != 'M' && op != 'T')
            op = getchar();
        if (op == 'D')
        {
            read(x);
            mul = (mul * inv(x)) % mod;
            q.erase(q.find(x));
        }
        else if (op == 'B')
            write(*q.rbegin()), putchar('\n');
        else if (op == 'S')
            write(*q.begin()), putchar('\n');
        else if (op == 'M')
        {
            x = *q.rbegin(), y = *q.begin();
            write(qpow(x, y));
            putchar('\n');
        }
        else
            write((int(mul % mod + mod)) % mod), putchar('\n');
    }
}
int main()
{
    FMain.Read();
    FMain.Run();
    return 0;
}