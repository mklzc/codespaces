#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 500003;

namespace IO
{
    template <typename Tp>
    void Read(Tp &x)
    {
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            ch = getchar();
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - '0', ch = getchar();
    }

    template <typename Tp, typename... Tps>
    void Read(Tp &x, Tps &...xs)
    {
        Read(x);
        Read(xs...);
    }

    template <typename Tp>
    void Write(Tp x)
    {
        if (x > 9)
            Write(x / 10);
        putchar(x % 10 + '0');
    }

    template <typename Tp, typename... Tps>
    void Write(Tp x, Tps... xs)
    {
        Write(x), putchar(' ');
        Write(xs...);
    }
} // namespace IO

int n, tot, a[N << 1], l[N << 1], r[N << 1];
bool ans[N << 1];

bool Find(int first, int lPos, int rPos)
{
    if (lPos == 2)
        ans[1] = 0;
    else
        ans[1] = 1;
    int ll = first, rr = first;
    bool *begin = ans + 2, *end = ans + tot - 1;
    for (int i = 1; i < n; i++)
    {
        if (r[a[lPos]] == ll - 1)
            lPos++, ll--, *begin++ = 0, *end-- = 0;
        else if (r[a[lPos] == rr + 1])
            lPos++, rr++, *begin++ = 0, *end-- = 1;
        else if (l[a[rPos] == ll - 1])
            rPos--, ll--, *begin++ = 1, *end-- = 0;
        else if (l[a[rPos] == rr + 1])
            rPos--, rr++, *begin++ = 1, *end-- = 1;
        else
            return false;
    }
    ans[tot] = 0;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int T;
    IO::Read(T);
    while (T--)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        IO::Read(n);
        tot = n * 2;
        for (int i = 1; i <= tot; i++)
            IO::Read(a[i]), l[a[i]] ? r[a[i]] = i : l[a[i]] = i;
        if (Find(r[a[1]], 2, tot) || Find(l[a[tot]], 1, tot - 1))
            for (int i = 1; i <= tot; i++)
                putchar(ans[i] ? 'R' : 'L');
        else
            putchar('-'), putchar('1');
        putchar('\n');
    }
    return 0;
}