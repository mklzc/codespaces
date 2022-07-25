#include <bits/stdc++.h>
#define fin freopen("in", "r", stdin)
#define fout freopen("out", "w", stdout)
#define int long long
#define rep(var, st, ed) for(int var = st; var <= ed; var++)
namespace IO{
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args&... args) {read(x);read(args...);}
};
using IO::read;
int T, mod, d;
std::vector<int> seq, ans;
int qpow(int a, int b, int mod)
{
    int res = 1;
    for (; b; b >>= 1){
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }return res;
}
int getphi(int x){
    int res = x;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) {
            res = res * (i - 1) / i;
            while (x % i == 0) x /= i;
        }
    }if (x > 1) res = res * (x - 1) / x;
    return res;
}
void getfac(int x) {
    int sav = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            seq.push_back(sav / i);
        }
    } if (x > 1) seq.push_back(sav / x);
}
int gcd(int x, int y){return y ? gcd(y, x % y) : x;}
bool check(int x)
{
    for (auto y : seq)
        if (qpow(x, y, mod) == 1) return false;
    return gcd(x, mod) == 1;
}
signed main()
{
    read(T);
    while (T--)
    {
        seq.clear(), seq.shrink_to_fit();
        ans.clear(), ans.shrink_to_fit();
        read(mod, d);
        if (mod == 2){
            if (d == 1) puts("1\n1");
            else puts("1\n");continue;
        }
        int phi = getphi(mod), yg = 0;
        getfac(phi);
        rep(i, 1, 200)
            if (check(i)) {yg = i; break;}
        int len = 1;
        if (yg) {
            ans.push_back(-1);
            rep(i, 1, phi - 1)
                if (gcd(i, phi) == 1) ans.push_back(qpow(yg, i, mod));
            std::sort(ans.begin(), ans.end());
            len = ans.size();
        }
        printf("%d\n", len - 1);
        for (int i = d; i < len; i += d)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}