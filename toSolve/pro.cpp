#include <iostream>
typedef long long Number;
const Number M = 103, N = 32, BIT = 16, P = 998244353;
Number n, m, K;
Number a[M], f[M][N][N][BIT];
Number C[N][N];
typedef long long LL;
LL fac[N], inv[N];
LL Combine(int x, int y)
{
    return fac[x] * inv[x - y] % P * inv[y] % P;
}
inline void init(int n) 
{
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

int Count(int n)
{
	int res = 0;
	while (n) res += n & 1, n >>= 1;
	return res;
}

int Power(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) res = 1ll * res * res % P;
        x = 1ll * x * x % P;
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    using std::cin;
    using std::cout;
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> K;
    Init();
    cout << Combine(6, 4) << " ";
    for (int i = 0; i <= m; i++)
        cin >> a[i];
    f[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= K; k++)
				for (int p = 0; p <= n >> 1; p++)
					for (int t = 0; t <= n - j; t++) 
                        f[i + 1][j + t][k + (t + p & 1)][t + p >> 1] += f[i][j][k][p] * Power(i, t) % P * Combine(n - j, t) % P;
    Number ans = 0;
	for (int k = 0; k <= K; k++)
		for (int p = 0; p <= n >> 1; p++)
			if (k + Count(p) <= K) ans = (ans + f[m + 1][n][k][p]) % P;
    std::cout << ans << "\n";
    return 0;
}