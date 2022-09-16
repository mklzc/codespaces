#include <bits/stdc++.h>
const int Maxn = 1e5 + 5;
int n, mdep[Maxn], son[Maxn];
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1], idx;
long long ans, *f[Maxn], *g[Maxn], buf[Maxn << 3], *now = buf;
void add(int x, int y)
{
	ver[++idx] = y;
	Next[idx] = head[x];
	head[x] = idx;
}
void init(int x, int fa)
{
	mdep[x] = mdep[fa] + 1;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (y == fa) continue;
		init(y, x);
		if (mdep[son[x]] < mdep[y]) son[x] = y;
	}
	mdep[x] = mdep[son[x]] + 1;
}
void dfs(int u, int fa)
{
	if (son[u])
		f[son[u]] = f[u] + 1, g[son[u]] = g[u] - 1, dfs(son[u], u);
	f[u][0] = 1, ans += g[u][0];
	for (int i = head[u]; i; i = Next[i])
	{
		int v = ver[i];
		if (v == fa || v == son[u]) continue;
		f[v] = now, now += (mdep[v] + 1) << 1;
		g[v] = now, now += (mdep[v] + 1);
		dfs(v, u);
		for (int j = 0; j < mdep[v]; j++) ans += f[u][j] * g[v][j + 1];
		for (int j = 1; j <= mdep[v]; j++) ans += g[u][j] * f[v][j - 1];
		for (int j = 0; j < mdep[v]; j++) g[u][j] += g[v][j + 1];
		for (int j = 1; j <= mdep[v]; j++) g[u][j] += f[u][j] * f[v][j - 1];
		for (int j = 1; j <= mdep[v]; j++) f[u][j] += f[v][j - 1];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	init(1, 0);
	f[1] = now, now += (mdep[1] + 1) << 1;
	g[1] = now, now += (mdep[1] + 1);
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}