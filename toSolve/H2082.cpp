//url: https://vjudge.net/problem/HDU-2082
#include <cstdio>

struct Node
{
    static const int N = 65;
    int a[N], b[N];
    void raw()
    {
        int T;
        scanf("%d", &T);
        while (T--)
        {
            for (int i = 1; i <= 50; i++)
                a[i] = b[i] = 0;
            a[0] = 1;
            for (int i = 1; i <= 26; i++)
            {
                int num;
                scanf("%d", &num);
                for (int j = 0; j <= 50; j++)
                    for (int k = 0; k <= num && k * i + j <= 50; k++)
                        b[i * k + j] += a[j];
                for (int i = 0; i <= 50; i++)
                    a[i] = b[i], b[i] = 0;
            }
            int ans = 0;
            for (int i = 1; i <= 50; i++)
                ans += a[i];
            printf("%d\n", ans);
        }
    }
}work;
int main()
{
    work.raw();
    return 0;
}