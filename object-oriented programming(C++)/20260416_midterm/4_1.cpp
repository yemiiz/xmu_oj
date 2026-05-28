#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
bool isprime(int n)
{
    if (n == 2 || n == 3)
        return true;
    else if (n % 2 == 0)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        if (isprime(x))
        {

            mp.insert(make_pair(x, 1));
        }
        else
        {
            bool flag = true;
            while (flag)
            {
                for (int j = 2; j <= sqrt(i)+1; j++)
                {
                    if (x % j == 0)
                    {

                        mp[j]++;
                    }
                    x /= j;
                    if (isprime(x))
                    {

                        flag = false;
                        if (x != 1)
                            mp[x]++;
                        break;
                    }
                }
            }
        }
    }
    for (auto &[num1, num2] : mp)
    {
        cout << num1 << ' ' << num2 << endl;
    }
    return 0;
}
