#include <bits/stdc++.h>
const int Maxn = 50;
struct BigNum
{
    std::string s;
    BigNum friend operator*(const BigNum &x, const BigNum &y)
    {
        static int a[Maxn], b[Maxn], c[Maxn];
        int lx = x.s.size(), ly = y.s.size();
        for (int i = 1; i <= lx; i++) a[i] = x.s[lx - i] - '0';
        for (int i = 1; i <= ly; i++) b[i] = y.s[ly - i] - '0';
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= lx; i++)
            for (int j = 1; j <= ly; j++)
                c[i + j - 1] = a[i] * b[j];
        int l = lx + ly;
        while (!c[l] && l > 1) l--;
        BigNum ans;
        for (int i = 0; i < l; i++)
            ans.s[i] = char(c[l - i]);
        return ans;
    }
};
const std::string INF = "100000000";
BigNum f[Maxn][Maxn];
std::string num;
int n, k;
int main()
{
    scanf("%d %d", &n, &k);
    std::cin >> num;
    num = "0" + num;
    for (int i = 1; i <= n; i++)
        f[0][i].s.push_back(num[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int l = 1; l <= i; l++)
            {
                BigNum sav = f[i - l + 1][j - 1] * (BigNum){num.substr(i - l + 1, l)};
                if (f[i][j].s < sav.s || f[i][j].s.empty()) f[i][j] = sav;
            }
        }
    }
    std::cout << f[n][k].s;
    return 0;
}