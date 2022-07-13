#include <cstdio>
#include <algorithm>
int a[1000003];
int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int x;
    for (int i = 1; i <= 100000; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }
    std::sort(a, a + 100000, [&](int x, int y)->bool{return x > y;});
    puts("");
    return 0;
}