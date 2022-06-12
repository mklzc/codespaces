#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> G[N];
int n, m;
inline int raw()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
    }
    return 0;
}
int main()
{

    return raw();
}