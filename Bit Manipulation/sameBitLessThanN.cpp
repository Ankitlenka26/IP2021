#include <iostream>
#define ll long long
using namespace std;

int csb(ll n)
{
    int res = 0;

    while (n > 0)
    {
        ll rsb = n & -n;
        n -= rsb;
        res++;
    }

    return res;
}
ll ncr(ll n, ll r)
{
    if (n < r)
    {
        return 0;
    }

    ll res = 1;

    for (ll i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

ll solution(ll n, int k, int i)
{
    if (i == 0)
    {
        return 0;
    }

    ll mask = 1L << i;

    ll res = 0;

    if ((n & mask) == 0)
    {
        // last bit will be zero (rightmost bit)
        res = solution(n, k, i - 1);
        // cout << res << endl ;
    }
    else
    {
        ll res1 = solution(n, k - 1, i - 1);
        ll res2 = ncr(i, k);
        // cout << res1 << " " << res2 << endl;
        res = res1 + res2;
    }

    return res;
}
int main()
{
    ll n;
    cin >> n;
    int k = csb(n);
    cout << solution(n, k, 63) << endl;
    return 0;
}