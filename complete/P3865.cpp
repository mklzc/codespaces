#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N];
int f[N][25];
inline void raw()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    for (int j = 1; (1 << j - 1) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (i + (1 << j - 1) <= n) f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            else f[i][j] = f[i][j - 1];
    int l, r;
    while (m--)
    {
        scanf("%d %d", &l, &r);
        int k = log2(r - l + 1);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }
}
int main() {return raw(), 0;}