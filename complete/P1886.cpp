#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
deque<int> q;
struct Node
{
    int Min, Max;
} ans[N];
int n, k, x[N];
inline int raw()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
        while (!q.empty() && q.back() <= i - k)
            q.pop_back();
        while (!q.empty() && x[i] < x[q.front()])
            q.pop_front();
        q.push_front(i);
        ans[i].Min = x[q.back()];
    }
    q.clear();
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.back() <= i - k)
            q.pop_back();
        while (!q.empty() && x[i] > x[q.front()])
            q.pop_front();
        q.push_front(i);
        ans[i].Max = x[q.back()];
    }
    for (int i = k; i <= n; i++)
        printf("%d ", ans[i].Min);
    putchar('\n');
    for (int i = k; i <= n; i++)
        printf("%d ", ans[i].Max);
    putchar('\n');
    return 0;
}
int main() { return raw(); }