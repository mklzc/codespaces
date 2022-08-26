#include <bits/stdc++.h>
const int Maxn = 105;
int r, s, p;
double f[Maxn][Maxn][Maxn];
int main()
{
    scanf("%d %d %d", &r, &s, &p);
    auto fr = [](int x, int y) ->double{
        return double(y) / double(x);
    };
    f[r][s][p] = 1;  
    for (int i = r; i >= 0; i--)
    {
        for (int j = s; j >= 0; j--)
        {
            for (int k = p; k >= 0; k--)
            {
                int tot = i * j + i * k + j * k;
                if (j - 1 >= 0 && i * j != 0) f[i][j - 1][k] += f[i][j][k] * fr(tot, i * j);
                if (k - 1 >= 0 && j * k != 0) f[i][j][k - 1] += f[i][j][k] * fr(tot, j * k);
                if (i - 1 >= 0 && k * i != 0) f[i - 1][j][k] += f[i][j][k] * fr(tot, k * i);
                // std::cout << fr(tot, k * i) << " ";
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
    printf("%.9lf %.9lf %.9lf", ansr, anss, ansp);
    return 0;
}