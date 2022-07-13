#include <cstdio>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
const int N = 1e5 + 5;
int a[N];
namespace temp{
	std::ostream_iterator<int>out(std::cout, " ");
};
using namespace temp;
int main()
{
	freopen("out", "w", stdout);
	for (int i = 1; i <= 100000; i++)
		a[i] = i;
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(a, a + 100000, g);
	copy(a + 1, a + 100000 + 1, out);
	return 0;
}
