#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define ll long long int
// space optimised seive using bitset
// checking if large number is a prime or not

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;
void seive()
{
    // set all bits
    b.set(); // 1,1,1,1,1,1
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(ll num)
{
    if (num < n)
    {
        return b[num] == 1 ? true : false;
    }

    for (ll i = 0; primes[i] * (ll)primes[i] < num; i++)
    {
        if (num % primes[i] == 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    seive();
    if (isPrime(225914127259))
    {
        cout << "It is Prime" << endl;
    }
    else
    {
        cout << "It is not a Prime Number" << endl;
    }
    return 0;
}