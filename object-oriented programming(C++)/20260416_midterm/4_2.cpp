#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 埃氏筛找出所有 ≤n 的质数
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // 对每个质数 p，计算其在 n! 中的指数
    for (int p : primes)
    {
        int count = 0;
        long long power = p;
        while (power <= n)
        {
            count += n / power;
            power *= p;
        }
        cout << p << ' ' << count << endl;
    }

    return 0;
}
