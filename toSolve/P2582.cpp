#include <bits/stdc++.h>
const int Maxn = 8e5 + 5;
int n, f[Maxn], g[Maxn], vis[Maxn];
void print_array(int *f, int len)
{
    for (int i = 1; i <= len; i++)
        std::cout << f[i] << " "; 
    std::cout << std::endl; 
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        int x = i; g[x] = 1;
        do {g[f[x]] = f[g[x]], vis[x] = 1, x = f[x];} while(x != i);
    }
    print_array(g, n);
    return 0;
}