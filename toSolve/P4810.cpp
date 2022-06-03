// url: https://www.luogu.com.cn/problem/P4810
// Author: lzc
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n;
vector<int> G[N];

inline void rai()
{
    scanf("%d", &n);
    char ch[2];
    int v, w;
    for (int i = 1; i <= n; i++)
    {
        if (ch[0] == 'a')
        {
            scanf("%s %d", ch, &v);
        }
        else if (ch[0] == 'b')
        {
            scanf("%s %d", ch, &v);
        }
        else
        {
            scanf("%s %d %d", ch, &v, &w);
        }
    }
}
int main()
{
    freopen("in", "r", stdin);
    rai();
    return 0;
}