#include <bits/stdc++.h>
double a, b, c, d;
bool f(double x) {return (a * x * x * x + b * x * x + c * x + d) > 0;}
double solve(double l, double r)
{
    static const double eps = 1e-6;
    double mid;
    while (r - l > eps)
    {
        mid = (l + r) / 2;
        if (f(mid) ^ f(r)) l = mid;
        else r = mid;
    }
    return mid;
}
int main()
{
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double pos1, pos2;
    bool fl = f(-100), fr = f(100), flag1 = false, flag2 = false;
    for (int i = -100; i <= 100; i++)
    {
        if (f(i) ^ fl && !flag1) pos1 = i, flag1 = true;
        if (f(i) ^ fr && !flag2 && flag1) pos2 = i, flag2 = true;
    }
    printf("%.2lf %.2lf %.2lf\n", solve(-100, pos1), solve(pos1, pos2), solve(pos2, 100));
    return 0;
}