#include <cstdio>
#include <algorithm>
#include <iostream>
#define filein freopen("in", "r", stdin)
class Main
{
public:
    static const int N = 2e6 + 5;
    int vis[N + 5], primes[N >> 2], cnt;
    void Init(void);
    int Find(int x);
    void Readexe(void);
} FMain;
int Main::Find(int x)
{
    int l = 0, r = cnt;
    while (l <= r)
    {
        int mid = (l + r + 1) >> 1;
        if (x < primes[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return primes[r];
}
void Main::Init()
{  
    cnt = 0, primes[0] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
            vis[i] = i, primes[++cnt] = i;
        for (int j = 1; j <= cnt && primes[j] * i <= N; j++)
        {
            vis[primes[j] * i] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}
void Main::Readexe()
{
    Init();
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", Find(n));
    }
}
int main()
{
    FMain.Readexe();
    return 0;
}