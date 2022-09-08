#include <bits/stdc++.h>
const int Maxn = 2010;
int n, m, k, fa[Maxn];
std::vector<int> q;
int get(int x) { return (x != fa[x]) ? (fa[x] = get(fa[x])) : x; }
int pre(int x, int len) { return x - len + 1; }
int suf(int x, int len) { return x + len - 1; }
const int mod = 1e9 + 7;
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
    } return res;
}
int main()
{
    std::iota(fa + 1, fa + Maxn, 1);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = pre(i, k); j <= i; j++)
        {
            int st = j, ed = suf(j, k), pos = i;
            if (st < 1 || ed > n) continue;
            int len = pos - st + 1;
            int new_pos = pre(ed, len);
            fa[get(pos)] = get(new_pos);
        }
    }
    for (int i = 1; i <= n; i++)
        q.push_back(get(i));
    std::sort(q.begin(), q.end());
    q.erase(std::unique(q.begin(), q.end()), q.end());
    printf("%d\n", qpow(m, q.size()));
    return 0;
}