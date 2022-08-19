#include <bits/stdc++.h>
const int Maxn = 55;
std::string s;
int stack[Maxn], top;

int get_num(int l, int r)
{
    int x = 0;
    for (int i = l; i <= r; i++)
        x = x * 10 + s[i] - '0';
    return x;
}

int calc(char ch)
{
    int x = stack[top--], y = stack[top];
    if (ch == '-') return y - x;
    if (ch == '*') return y * x;
    if (ch == '+') return y + x;
    if (ch == '/') return y / x;
    return -1;
}
int main()
{
    std::cin >> s;
    int lst = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            // std::cout << lst << " " << i - 1 << " " << get_num(lst, i - 1) << "\n";
            stack[++top] = get_num(lst, i - 1);
        }
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
        {
            // print(stack, top);
            int x = calc(s[i]);
            stack[top] = x;
        }
        if (s[i] == '@')
            return printf("%d\n", stack[top]), 0;
        if ('0' <= s[i] && s[i] <= '9')
            continue;
        lst = i + 1;
    }
    return 0;
}