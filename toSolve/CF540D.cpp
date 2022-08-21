#include <bits/stdc++.h>
const int Maxn = 105;
int r, s, p;
double f[Maxn][Maxn][Maxn];
int main()
{
    scanf("%d %d %d", &r, &s, &p);
    auto calc = [](int x, int y) ->double{
        return double(x) / double(y);
    };
    for (int i = r; i >= 0; i--)
    {
        for (int j = s; j >= 0; j--)
        {
            for (int k = p; k >= 0; k--)
            {
                int tot = i + j + k + 2;
                f[i][j][k] += f[i + 1][j + 1][k] * calc(tot, i + 1) * calc(tot, j + 1);
                f[i][j][k] += f[i + 1][j][k + 1] * calc(tot, i + 1) * calc(tot, k + 1);
                f[i][j][k] += f[i][j + 1][k + 1] * calc(tot, j + 1) * calc(tot, k + 1);
            }
        }
    }
    double ansr = 0, anss = 0, ansp = 0;
    for (int i = 1; i <= r; i++)
        ansr += f[i][0][0];
    for (int i = 1; i <= s; i++)
        anss += f[0][i][0];
    for (int i = 1; i <= p; i++)
        ansp += f[0][0][i];
    return 0;
}