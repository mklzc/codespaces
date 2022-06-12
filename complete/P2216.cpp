// url: https://www.luogu.com.cn/problem/P2216
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a, b, n, f[N][N];
deque<int> q, p;
struct Node
{
    int Min, Max;
} col[N][N], ans[N][N];
inline void work()
{
    for (int i = 1; i <= a; i++)
    {
        q.clear(), p.clear();
        for (int j = 1; j <= b; j++)
        {    
            while (!q.empty() && q.back() <= j - n)
                q.pop_back();
            while (!p.empty() && p.back() <= j - n)
                p.pop_back();
            while (!q.empty() && f[i][j] < f[i][q.front()])
                q.pop_front();
            while (!p.empty() && f[i][j] > f[i][p.front()])
                p.pop_front();
            q.push_front(j), p.push_front(j);
            if (j < n) continue;
            col[i][j].Min = f[i][q.back()];
            col[i][j].Max = f[i][p.back()];
        }
    }
    for (int i = n; i <= b; i++)
    {
        q.clear(), p.clear();
        for (int j = 1; j <= a; j++)
        {
            
            while (!q.empty() && q.back() <= j - n)
                q.pop_back();
            while (!p.empty() && p.back() <= j - n)
                p.pop_back();
            while (!q.empty() && col[j][i].Min < col[q.front()][i].Min)
                q.pop_front();
            while (!p.empty() && col[j][i].Max > col[p.front()][i].Max)
                p.pop_front();
            q.push_front(j);
            p.push_front(j);
            ans[j][i].Min = col[q.back()][i].Min;
            ans[j][i].Max = col[p.back()][i].Max;
        }
    }
        
    int Ans = 0x3f3f3f3f;
    for (int i = n; i <= a; i++)
        for (int j = n; j <= b; j++)
            Ans = min(Ans, ans[i][j].Max - ans[i][j].Min);
    printf("%d\n", Ans);
}
inline int rai()
{
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            scanf("%d", &f[i][j]);
    work();
    return 0;
}
int main() { return rai(); }