#include <bits/stdc++.h>
#define infile freopen("in", "r", stdin)
#define outfile freopen("out", "w", stdout)
class IO
{
public:
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T w = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            x = x * 10 + ch - 48, ch = getchar();
        x = x * w;
    }
    template <typename T, typename... Args>
    inline void read(T &x, Args &...args)
    {
        read(x);
        read(args...);
    }
} io;
class Main
{
public:
    void Read(void);
    void reset(void);
    int Tail(int l, int r);
    int Head(int l, int r);
    int Common(int l, int r);
    bool check(int len);

private:
    static const int N = 8e3 + 5;
    int n, Q, s[N], q[N], tmp[N];
} FMain;
void Main::reset()
{
    int i = 1;
    while (q[i] != -1)
        q[i++] = -1;
}
int Main::Tail(int l, int r)
{
    int cnt = 0, ptr = 0;
    int i = r - 1;
    q[++ptr] = s[r];
    while (i >= l)
    {
        /* std::cout << ptr << " q: ";
        for (int j = 1; j <= ptr; j++)
            std::cout << q[j] << " ";
        std::cout << '\n'; */
        if (s[i] == 1)
            q[++ptr] = s[i];
        else if (s[i] == 0)
        {
            ptr--;
            if (ptr == 0)
                cnt++;
            if (ptr < 0)
                return cnt;
        }
        i--;
    }
    return cnt;
}
int Main::Head(int l, int r)
{
    int cnt = 0, ptr = 0;
    int i = l + 1;
    q[++ptr] = s[l];
    while (i <= r)
    {
        if (s[i] == 0)
            q[++ptr] = s[i];
        else
        {
            ptr--;
            if (ptr == 0)
                cnt++;
            else if (ptr < 0)
                return cnt;
        }
        i++;
    }
    return cnt;
}
bool Main::check(int len)
{
    int ptr = 0, res1 = 0, res0 = 0;

    for (int i = 1; i <= len; i++)
    {
        if (tmp[i] == 0)
            q[++ptr] = 0, res0++;
        else
        {
            res1++, --ptr;
            if (ptr < 0)
                return false;
        }
    }
    if (res1 != res0)
        return false;
    return true;
}
int Main::Common(int l, int r)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
        for (int j = i; j <= r; j++)
        {
            int len = 0;
            for (int k = l; k <= i - 1; k++)
                tmp[++len] = s[k];
            for (int k = j + 1; k <= r; k++)
                tmp[++len] = s[k];
            if (check(len))
                cnt++;
        }
    return cnt;
}
void Main::Read()
{
    io.read(n, Q);
    for (int i = 1; i <= n; i++)
    {
        q[i] = -1;
        char ch = getchar();
        if (ch == '(')
            s[i] = 0;
        else if (ch == ')')
            s[i] = 1;
    }
    q[n + 1] = -1;
    int l, r;
    while (Q--)
    {
        io.read(l, r);
        if (s[l] && !s[r])
        {
            puts("1");
            continue;
        }
        else if (s[l])
            printf("%d\n", Tail(l, r) + 1);
        else if (!s[r])
            printf("%d\n", Head(l, r) + 1);
        else
            printf("%d\n", Common(l, r));
    }
}
int main()
{
    infile;
    outfile;
    FMain.Read();
    return 0;
}