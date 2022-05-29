// url: https://www.luogu.com.cn/problem/P7915
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5 + 5;
int n, a[N];
const int N = 5e5 + 5;
deque<int> q, p;
inline pii fget()
{
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n * 2; i++)
        if (a[i] == a[1] && a[i] != a[1]) res1 = i;
        else if (a[i] == a[n * 2] && a[i] != a[n * 2]) res2 = i;
    return make_pair(res1, res2);
}
inline pii check()
{
    static int a[4];
    a[0] = q.front(), a[1] = q.back(), a[2] = p.front(), a[3] = p.back();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i] == a[j]) return make_pair(i, j);
    return make_pair(0, 0);
}
string Ans;
void calc(int i, int j)
{
    if (i == 0 || j == 0)
        Ans.push_back('L');
}
inline pii work()
{
    pii ans, pos = fget();
    for (int i = 1; i < pos.first; i++)
        q.push_front(a[i]);
    for (int i = pos.first + 1; i <= 2 * n; i++)
        p.push_back(a[i]);
    for (int i = 1; i <= 2 * (n - 1); i++)
    {
        auto res = fget();
        if (!res.first) {ans.first = false; break;}
    }
}
inline void rai()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= n * 2; i++)
            scanf("%d", &a[i]);
    }
}
int main()
{
    return 0;
}