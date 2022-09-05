#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#define eb emplace_back
#define fi first
#define se second
#define IL inline
namespace FIO
{
	const int L = (1 << 20) + 100;
	char buf[L], out[L], *S, *E;
	int l = 0;
	#define gh() (S == E ? E = (S = buf) + fread(buf, 1, L, stdin), (S == E ? EOF : *S++) : *S++)
	IL void flus(){ fwrite(out, 1, l, stdout), l = 0; }
	IL void chk(){ if (l >= L - 100) flus(); }
	IL void putc(char x){ out[l++] = x, chk(); }
	IL void wt(const char *s){ while (*s != '\0') putc(*s++); }
	template<typename T>
	IL void rd(T &x)
	{
		char ch = gh(), t = 0;
		for (; ch < '0' || ch > '9'; ch = gh()) t |= ch == '-';
		for (x = 0; ch >= '0' && ch <= '9'; ch = gh()) x = x * 10 + (ch ^ 48);
		if (t) x = -x;
	}
	template<typename T>
	IL void wt(T x)
	{
		if (x < 0) putc('-'), x = -x;
		if (x > 9) wt(x / 10);
		out[l++] = x % 10 + 48, chk();
	}
	template<typename T, typename ...Args>
	IL void rd(T &x, Args &...args){ rd(x), rd(args...); }
	template<typename T, typename ...Args>
	IL void wt(T x, Args ...args){ wt(x), wt(args...); }
	#undef gh
}
using FIO::flus;
using FIO::rd;
using FIO::wt;
const int N = 5e6 + 100;
int n, m, mxd;
int ans[N], as[N], d[N];
std::vector<int> g[N];
struct Edge{ int ne, ver; } e[N];
int h[N], idx;
IL void add(int x, int y){ e[idx] = {h[x], y}, h[x] = idx++; }
IL void dp(int x, int dep)
{
    d[x] = dep;
    mxd = std::max(mxd, dep);
    g[dep].eb(x);
    for (int i = h[x], y; ~i; i = e[i].ne)
    {
        dp(y = e[i].ver, dep + 1);
        d[x] = std::max(d[x], d[y]);
    }
}
int main()
{
    rd(n, m);
    std::memset(h, -1, sizeof h), idx = 0;
    for (int i = 1, fa; i <= n; ++i) rd(fa), add(fa, i);
    dp(1, 1);
    std::iota(ans + 1, ans + 1 + n, 1);
    std::pair<int, int> mx, mx2;
    for (int i = 1, las = 1; i <= mxd; ++i)
    {
        las = std::max(las, i);
        mx = {0, 0}, mx2 = {0, 0};
        for (int x : g[i])
            if (d[x] > mx.fi) mx2 = mx, mx = {d[x], x};
            else mx2 = std::max(mx2, {d[x], x});
        as[i] = mx.se;
        if (!mx2.fi) continue;
        while (las <= mx2.fi)
            ans[las++] = i - 1;
    }
    for (int i = 1; i <= mxd; ++i) ans[i] = as[ans[i]];
    for (int k; m--; ) 
    {
        rd(k);
        wt(ans[k], "\n");
    }
    return flus(), 0;
}