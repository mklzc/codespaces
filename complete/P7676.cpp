#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;
typedef long long LL;
double k[N];
LL n, ans = 0, cnt[N], idx;
vector<double> q;
inline LL work()
{
    for (int i = 1; i <= idx; i++)
        ans += (cnt[i] - cnt[i - 1]) * cnt[i - 1] % mod * (n - cnt[i]) % mod;
    return ((ans % mod) + mod) % mod;
}
inline void rai()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        k[i] = -1.0 * double(a) / double(b);
        q.push_back(k[i]);
    }
    sort(q.begin(),q.end());
    idx++, cnt[1] = 1;
    for (int i = 1; i < q.size(); i++)
        if (q[i] == q[i - 1]) cnt[idx]++;
        else idx++, cnt[idx] = 1;
    for (int i = 1; i <= idx; i++)
        cnt[i] += cnt[i - 1];
}
int main()
{
    rai();
    printf("%lld\n", work());
    return 0;
}