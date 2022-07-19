// url: https://www.luogu.com.cn/problem/P1270
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
const int N = 1050;
int arrive_time;
struct Node
{
    int cost, num;
}t[N << 3];
void Read(int p)
{
    scanf("%d %d", &t[p].cost, &t[p].num);
    t[p].cost *= 2;
    if (!t[p].num)
        Read(p << 1), Read(p << 1 | 1);
}
int f[N][N];
void dp(int p, int left)
{
    if (f[p][left] || !left) return;
    int remain = left - t[p].cost;
    if (t[p].num)
        return void(f[p][left] = std::min(t[p].num, remain / 5));
    for (int i = 0; i <= remain; i++)
    {
        dp(p << 1, i);
        dp(p << 1 | 1, remain - i);
        f[p][left] = std::max(f[p][left], f[p << 1][i] + f[p << 1 | 1][remain - i]);
    }
}
int main()
{
    scanf("%d", &arrive_time);
    Read(1);
    dp(1, arrive_time - 1);
    printf("%d\n", f[1][arrive_time - 1]);
    return 0;
}