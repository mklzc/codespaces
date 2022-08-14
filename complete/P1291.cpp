#include <bits/stdc++.h>
using LL = long long;
int get_digit(LL x)
{
    int cnt = 0;
    while (x) x = x / 10, cnt++;
    return cnt;
}
void out(int cnt, char ch) { while (cnt--) std::cout << ch; }
struct Node
{
    LL de, nu;
    Node(LL _de = 1, LL _nu = 0) {nu = _nu, de = _de;}
    void print()
    {
        LL sav = nu / de;
        if (!nu) return void(puts("0"));
        if (de == 1) return void(std::cout << nu);
        if (!sav)
        {
            int d = get_digit(de);
            std::cout << nu << "\n";
            out(d, '-');
            std::cout << "\n" << nu << "\n";
        }
        else
        {
            LL buf = nu - de * sav, d = get_digit(de);
            int space = get_digit(sav);
            out(space, ' '); std::cout << buf << "\n";
            std::cout << sav; out(d, '-'); std::cout << "\n";
            out(space, ' '); std::cout << de << "\n";
        }
    }
};
Node operator+(const Node &a, const Node &b)
{
    LL newde = a.de * b .de, newnu = a.de * b.nu + a.nu * b.de;
    LL d = std::__gcd(newde, newnu);
    return Node(newde / d, newnu / d);
}
const int Maxn = 50;
int n;
Node f[Maxn];
int main()
{
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--)
        f[i] = f[i + 1] + Node(n - i, n);
    f[0].print();
    return 0;
}