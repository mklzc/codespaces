#include <bits/stdc++.h>
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') { if (ch == '-') w = -1;ch = getchar();}
        while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
using LL = long long;
const int Maxn = 605;
LL a[Maxn], L, sum = 0;
int m;
LL cnt(int Weight)
{
    return a[Weight + m + 1];
}
void dfs()
{
}
int main()
{
    read(m, L);
    for (int i = 1, j = -m; i <= 2 * m + 1; i++, j++)
        read(a[i]), sum += j * a[i];
	return 0;
}