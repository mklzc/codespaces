#include <cstdio>
const int N = 100010;

int n, m;
double a[N], trSum[N << 2], trSquare[N << 2];

void PushUp(int p, int l, int r)
{
    trSum[p] = trSum[p << 1] + trSum[p << 1 | 1];
    trSquare[p] = trSquare[p << 1] + trSquare[p << 1 | 1];
}

void Build(int p = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        trSum[p] = a[l];
        trSquare[p] = a[l] * a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(p << 1, l, mid);
    Build(p << 1 | 1, mid + 1, r);
    PushUp(p, l, r);
}

int pos;
double val;
void Modify(int p = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        int res = trSum[p] + val;
        trSum[p] = res;
        trSquare[p] = res * res;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        Modify(p << 1, l, mid);
    else
        Modify(p << 1 | 1, mid + 1, r);
    PushUp(p, l, r);
}

int posx, posy;
double resSum, resSquare;
void Query(int p = 1, int l = 1, int r = n)
{
    if (posx <= l && r <= posy)
    {
        resSum = resSum + trSum[p];
        resSquare = resSquare + trSquare[p];
        return;
    }
    int mid = (l + r) >> 1;
    if (posx <= mid)
        Query(p << 1, l, mid);
    if (mid < posy)
        Query(p << 1 | 1, mid + 1, r);
}

double Fraction(double up, double down)
{
    return up / down;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%llf", &a[i]);
    Build();
    while (m--)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            scanf("%llf", &val);
            for (pos = x; pos <= y; pos++)
                Modify();
        }
        else
        {
            posx = x, posy = y, resSum = resSquare = 0;
            Query();
            int length = y - x + 1;
            double average = Fraction(resSum, length);
            if (opt == 2)
                printf("%.4lf\n", average);
            else
            {
                double variance = Fraction(resSquare, length) - average * average;
                printf("%.4lf\n", variance);
            }
        }
    }
    return 0;
}