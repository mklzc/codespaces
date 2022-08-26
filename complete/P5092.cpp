#include <bits/stdc++.h>
#include <bits/stdc++.h>
const int Maxn = 30010;
int n, fa[Maxn], sz[Maxn], d[Maxn];
int get(int x)
{
    if (x == fa[x]) return x;
    int rt = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = rt;
}
void merge(int x, int y)
{
    int fx = get(x), fy = get(y);
    fa[fx] = fy;
    d[fx] += sz[fy];
    sz[fy] += sz[fx];
}
int main()
{
    scanf("%d", &n);
    char op[5];
    for (int i = 1; i <= Maxn - 1; i++)
        sz[i] = 1, fa[i] = i;
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%s %d", op, &x);
        if (op[0] == 'M')
            scanf("%d", &y), merge(x, y);
        else if (op[0] == 'C')
        {
            get(x);
            printf("%d\n", d[x]);
        }
    }
    return 0;
}