#include <iostream>
using namespace std;
#define ll long long
void primeseive(int *p)
{

    // iterate over to all odd numbers and mark them as prime
    for (int i = 3; i <= 1000000; i += 2)
    {
        p[i] = 1;
    }

    // sieve logic will mark all non prime numbers as zero
    for (ll i = 3; i <= 1000000; i += 2)
    {
        if (p[i] == 1)
        {
            // mark all multiples of i as non prime
            for (ll j = i * i; j <= 1000000; j += 2 * i)
            {
                p[j] = 0; // marked the no as not prime because it is multiple of i
            }
        }
    }
    p[0] = p[1] = 0;
    p[2] = 1;
    return;
}

int main()
{
    int p[1000005] = {0};
    primeseive(p);
    int csum[1000005] = {0};
    for (int i = 1; i <= 1000000; i++)
    {
        csum[i] = p[i] + csum[i - 1];
    }
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a - 1] << endl;
    }
    return 0;
}