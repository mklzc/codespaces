#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <numeric>
const int Maxn = 5e4 + 5;
std::string s;
int fa[Maxn];
std::map<std::string, int> q;
std::map<int, std::string> sav;
int idx;
int get(int x)
{
    if (x != fa[x]) return fa[x] = get(fa[x]);
    return fa[x];
}
void merge(int x, int y)
{
    // if (x < y) std::swap(x, y);
    // std::cout << x << " " << y << ' ';
    // std::cout << "merg: " << sav[x].c_str() << " " << sav[y].c_str() << "\n";
    fa[get(x)] = get(y);
}
int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    std::iota(fa + 1, fa + Maxn, 1);
    int father;
    s.resize(15);
    while (true)
    {
        scanf("%s", &s[0]);
        // std::cout << s.c_str() << "\n";
        if (s[0] == '$') return 0;
        std::string buf = s.substr(1, s.size() - 1);
        if (s[0] == '#')
        {
            if (!q[buf]) q[buf] = ++idx, sav[idx] = buf;
            father = q[buf];
        }
        else if (s[0] == '+')
        {
            if (!q[buf]) q[buf] = ++idx, sav[idx] = buf;
            merge(q[buf], father);
        }
        else if (s[0] == '?')
        {
            int id = get(q[buf]);
            auto x = sav[id];
            printf("%s %s\n", buf.c_str(), x.c_str());
        }
    }
    return 0;
}