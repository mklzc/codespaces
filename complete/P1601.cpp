//url: https://www.luogu.com.cn/problem/P1601
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
class Calc
{
public:
    std::string add(std::string a, std::string b)
    {
        std::string c;
        int t = 0, la = a.size(), lb = b.size();
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        for (int i = 0; i < la || i < lb; i++)
        {
            if (i < la) t += a[i] - '0';
            if (i < lb) t += b[i] - '0';
            c.push_back(t % 10 + '0');
            t = t / 10;
        }
        if(t) c.push_back(t + '0');
        std::reverse(c.begin(), c.end());
        return c;
    }
} calc;
int main()
{
    std::string a, b;
    std::cin >> a >> b;
    std::cout << calc.add(a, b) << '\n';
    return 0;
}