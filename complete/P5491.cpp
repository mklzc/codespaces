#include <algorithm>
#include <cstdio>
#include <iostream>
using LL = long long;

int mod, c;
LL isq;
std::pair<LL, LL> cipolla()
{
    struct CP {
        LL x, y;
        CP operator*(CP const &B) 
        const {return (CP){(x * B.x + y * B.y % mod * isq) % mod, (x * B.y + y * B.x) % mod};}
        CP qpow(CP a, int b){
            CP res = (CP){1, 0};
            for (; b; b >>= 1) {
                if (b & 1) res = res * a;
                a = a * a;
            }return res;
        }
    };
    auto qpow = [](LL a, int b, int mod)
    ->int{
        int res = 1;
        for (; b; b >>= 1) {
            if (b & 1) res = 1ll * res * a % mod;
            a = a * a % mod;
        }return res;
    };
    auto check = [&](LL a, int mod)
    ->bool{return qpow(a, (mod - 1) >> 1, mod) == mod - 1;};
    
    if (!c) return {0, -1};
    if (check(c, mod)) return {-1, -1};
    int a;
    while (true)
    {
        a = rand() % mod;
        isq = (1ll * a * a - c + mod) % mod;
        if (check(isq, mod)) break;
    }
    CP i = i.qpow(CP{a, 1}, (mod + 1) >> 1);
    if (i.x > mod - i.x) return {mod - i.x, i.x};
    return {i.x, mod - i.x};
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &c, &mod);
        auto ans = cipolla();
        if (ans.first == -1) puts("Hola!");
        else if (!ans.first && ans.second == -1) puts("0");
        else printf("%lld %lld\n", ans.first, ans.second);
    }
        
    return 0;
}