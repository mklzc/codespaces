#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e7 + 10;
int a[Maxn], b[Maxn];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++)
        a[i] = i;
    n--;
    while (n--)
    {
        for (int i = 1; i <= k; i++)
            if (a[i] + 1 != a[i + 1]) {a[i]++; break;}
            else a[i] = i;
    }
    for (int i =  1; i <= k; i++)
        b[a[i]] = 1;
    for (int i = a[k]; i >= 1; i--)
        printf("%d", b[i]);
    return 0;
}
