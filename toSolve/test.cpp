#include <bits/stdc++.h>
const int N = 1e5 + 5;
int primes[N], v[N], phi[N], cnt;
int main()
{
    auto Case = [&](int x, int y)->int{return x % y != 0 ? x * (y - 1) : x * y;};
    phi[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!v[i]) primes[++cnt] = i, phi[i] = i - 1;
        for (int j = 1; j <= cnt && primes[j] * i <= N; j++)
        {
            v[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            phi[i * primes[j]] = Case(i, primes[j]);
        }
            
    }
    std::cout << phi[4] << "\n";
    return 0;
}