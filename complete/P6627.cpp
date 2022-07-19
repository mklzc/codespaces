// url: https://www.luogu.com.cn/problem/P1131
#include <bits/stdc++.h>
const int N = 1e6 + 5, inf = 0x3f3f3f3f;
struct Node
{
    int tp, l, r, point, val;
    Node(int _tp = 0, int _l = 0, int _r = 0, int _point = 0, int _val = 0){
        tp = _tp, l = _l, r = _r, point = _point, val = _val;
    }
} qlist[N];

int n, res[N], len;
std::vector<int> q;
template <typename T>
void Emplace(T x){q.emplace_back(x);}
template <typename T, typename... Args>
void Emplace(T x, Args... args){Emplace(x), Emplace(args...);}
void read_discrete()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, l, r, point, val;
        scanf("%d", &op);
        if (op == 1)
            scanf("%d %d %d", &l, &r, &val),
                Emplace(l, r, l - 1, r + 1);
        else if (op == 2)
            scanf("%d %d", &point, &val),
                Emplace(point, point + 1, point - 1);
        else
            scanf("%d %d", &point, &val),
                Emplace(point, point + 1, point - 1);
        qlist[i] = Node(op, l, r, point, val);
    }
    Emplace(0);
    std::sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    len = q.size();
}
int main()
{
    read_discrete();
    auto Find = [](int x) -> int{ return std::lower_bound(q.begin(), q.end(), x) - q.begin(); };
    auto cf = [](int l, int r, int val) {
        res[l] ^= val, res[r + 1] ^= val;
    };
    for (int i = 1; i <= n; i++)
    {
        int Point;
        if (qlist[i].tp == 1)
            cf(Find(qlist[i].l), Find(qlist[i].r), qlist[i].val);
        else if (qlist[i].tp == 3)
            Point = Find(qlist[i].point),
            cf(0, Point - 1, qlist[i].val),
            cf(Point + 1, len - 1, qlist[i].val);
        else
            Point = Find(qlist[i].point),
            cf(Point, Point, qlist[i].val);
    }
    int ans = res[0], pos = 0;
    for (int i = 1; i < len; i++)
    {
        res[i] ^= res[i - 1];
        if (res[i] > ans)
            ans = res[i], pos = i;
        else if (ans == res[i])
            if (abs(q[i]) < abs(q[pos])) pos = i;
    }
    printf("%d %d\n", ans, q[pos]);
    return 0;
}