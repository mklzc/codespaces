//url: https://www.luogu.com.cn/problem/P3904
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
class Calc
{
public:
    std::string add(std::string a, std::string b)
    {
        std::string c;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int la = a.size(), lb = b.size(), t = 0;
        for (int i = 0; i < a.size() || i < b.size(); i++)
        {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            c.push_back(t % 10 + '0');
            t = t / 10;
        }
        if (t) c.push_back(t + '0');
        reverse(c.begin(), c.end());
        return c;
    }
    std::vector<int> c;
    std::string mul(std::string a, int b)
    {
        reverse(a.begin(), a.end());
        c.clear();
        int la = a.size(), t = 0;
        for (int i = 0; i < a.size(); i++)
        {
            t += (a[i] - '0') * b;
            c.push_back(t % 10);
            t = t / 10;
        }
        if (t) c.push_back(t);
        while (c.size() && !c.back()) c.pop_back();
        int lc = c.size() - 1;
        std::string str;
        for (int i = lc; i >= 0; i--)
            str += std::to_string(c[i]);
        return str;
    }
}calc;


class Main
{
private:
    static const int N = 55;
    std::string s[N][N];
    int n, m;
public:
    void Rexe();
} FMain;
void Main::Rexe()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = "0";
    s[1][1] = "1";
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            s[i][j] = calc.add(s[i - 1][j - 1], calc.mul(s[i - 1][j], j));
    }
    std::cout << s[n][m] << "\n";
}
int main()
{
    FMain.Rexe();
    return 0;
}