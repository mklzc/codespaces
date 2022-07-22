#include <bits/stdc++.h>
using LL = long long;
const int CEIL = 6000500;
int askn[15], N, scope;
bool v[CEIL];
int pr[CEIL], cnt;
LL phi[CEIL], mu[CEIL], smu[CEIL], sphi[CEIL], Tn;
inline void init()
{
    mu[1] = phi[1] = 1;
    for (int i = 2, t; i <= scope; i++)
    {
        if (!v[i])
            pr[++cnt] = i, phi[i] = i - 1, mu[i] = -1;
        for (int j = 1; j <= cnt && (t = pr[j] * i) <= scope; j++)
        {
            v[t] = 1;
            if (i % pr[j] == 0) {phi[t] = phi[i] * pr[j];break;}
            mu[t] = -mu[i], phi[t] = phi[i] * (pr[j] - 1);
        }
    }
    for (int i = 2; i <= scope; i++)
        mu[i] += mu[i - 1], phi[i] += phi[i - 1];
}
inline LL SMU(int n) {return n <= scope ? mu[n] : smu[N / n];}
inline LL SPHI(int n) {return n <= scope ? phi[n] : sphi[N / n];}
void work(LL n, int d)
{
    if (n <= scope || sphi[d]) return;
    LL tmu = 1, tphi = 1ll * n * (n + 1) >> 1;
    LL l = 2, r;
    while (l <= n)
    {
        r = n / (n / l);
        work(n / l, d * l);
        tmu -= SMU(n / l) * (r - l + 1);
        tphi -= SPHI(n / l) * (r - l + 1);
        l = r + 1;
    }
    smu[d] = tmu, sphi[d] = tphi;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        scanf("%d", &askn[i]), Tn += askn[i];
    scope = std::min((int)pow(Tn, 0.66) + 5, 6000000);
    init();
    for (int i = 1; i <= T; i++)
    {
        N = askn[i];
        memset(sphi,0,sizeof(sphi));
        work(N, 1);
        printf("%lld %lld\n", SPHI(N), SMU(N));
    }
    return 0;
}