#include <bits/stdc++.h>
const int Maxn = 50;
int n, k;
char num[Maxn];
std::string f[Maxn][Maxn];
std::string calc(int l, int r)
{
    std::string buf;
    for (int i = l; i <= r; i++)
        buf.push_back(num[i]);
    return buf;
}
int a[Maxn], b[Maxn], c[Maxn];
std::string mul(std::string x, std::string y)
{
    int lx = x.size(), ly = y.size();
    for (int i = 1; i <= lx; i++)
        a[i] = x[lx - i] - '0';
    for (int i = 1; i <= ly; i++)
        b[i] = y[ly - i] - '0';
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= lx; i++)
        for (int j = 1; j <= ly; j++)
            c[i + j - 1] += a[i] * b[j];
    int l = lx + ly;
    int t = 0;
    for (int i = 1; i < l; i++)
        if (c[i] > 9) c[i + 1] += c[i] / 10, c[i] %= 10;
    while (!c[l] && l > 0) l--;
    std::string res;
    for (int i = 0; i < l; i++)
        res.push_back(c[l - i] + '0');
    return res;
}
bool check(std::string x, std::string y)
{
    if (x.size() < y.size()) return true;
    if (x.size() > y.size()) return false;
    return x < y;
}
int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", num + 1);
    for (int i = 1; i <= n; i++)
        f[i][0] = calc(1, i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i && j <= k; j++)
        {
            for (int l = 1; l < i; l++)
            {
                std::string sav = mul(f[l][j - 1], calc(l + 1, i));
                if (check(f[i][j], sav)) f[i][j] = sav;
            }
        }
    }
    std::cout << f[n][k] << "\n";
    return 0;
}