#include <bits/stdc++.h>

const int start[27] = {0, 1, 2, 4, 7, 11, 16, 22, 29, 37, 46, 56, 67, 79, 92, 106, 121, 137, 154, 172, 191, 211, 232, 254, 277, 301, 326};

inline int GetId(const int &x, const int &y) { return x * (x - 1) / 2 + y; }

inline int GetX(const int &id)
{
    for (int i = 1; i <= 26; i++)
        if (id < start[i]) return i - 1;
}

inline int GetDown(const int &id, const bool &right)
{
    int x = GetX(id);
    int y = id - x * (x - 1) / 2;
    return GetId(x + 1, y + right);
}

const int N = 380;
int n, k, nd;
bool DOE[N], color[N];

int Print()
{
    int x = 1, y = 1;
    for (int i = 1; i <= nd; i++)
    {
        if (color[i]) putchar('B');
        else putchar('A');
        if (x == y) putchar('\n'), x++, y = 1;
        else y++;
    }
    return 0;
}

int tot;
void dfs(int id)
{
    if (id == nd)
    {
        tot++;
        if (tot == k) return void(Print());
        return;
    }
    if (DOE[id])
        return dfs(id + 1);
    int SON = GetDown(id, false);
    if (!DOE[SON] && !DOE[SON + 1])
    {
        DOE[id] = DOE[SON] = DOE[SON + 1] = true;
        color[id] = color[SON] = color[SON + 1] = false;
        dfs(id + 1);
        DOE[id] = DOE[SON] = DOE[SON + 1] = false;
    }
    int x = GetX(id);
    int y = id - x * (x - 1) / 2;
    SON = GetDown(id, true);
    if (x != y && !DOE[id + 1] && !DOE[SON])
    {
        DOE[id] = DOE[id + 1] = DOE[SON] = true;
        color[id] = color[id + 1] = color[SON] = true;
        dfs(id + 1);
        DOE[id] = DOE[id + 1] = DOE[SON] = false;
    }
    return;
}

int main()
{
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    scanf("%d %d", &n, &k);
    nd = GetId(n, n);
    for (int i = nd + 1; i <= nd + n + 2; i++)
        DOE[i] = true;
    dfs(1);
    return 0;
}