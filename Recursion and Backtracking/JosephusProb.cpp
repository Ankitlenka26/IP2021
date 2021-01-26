#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    int x = josephus(n - 1, k);
    int y = (x + k) % n;
    return y;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = josephus(n, k);
    cout << ans << endl;
    return 0;
}