#include <bits/stdc++.h>
const int N = 1e5 + 5;
struct Node
{
    int tp, l, r, point, val;
    Node(int _tp = 0, int _l = 0, int _r = 0, int _point = 0, int _val = 0) {
        tp = _tp, l = _l, r = _r, point = _point, val = _val;
    }
}t[N];
int n;
std::vector<int> q;
void read_discrete()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, l, r, point, val;
        scanf("%d", &op);
        if (op == 1)
            scanf("%d %d %d", &l, &r, &val),
            q.push_back(l),
            q.push_back(r);
        else if (op == 2)
            scanf("%d %d %d", &point, &val),
            q.push_back(point);
        else
            scanf("%d %d", &point, &val),
            q.push_back(point);
        t[i] = Node(op, l, r, point, val);
    }
    std::sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
}
int main()
{
    return 0;
}