#include <iostream>
#include <vector>
using namespace std;

int helper(int n, vector<int> &mem)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (mem[n] != 0)
    {
        return mem[n];
    }

    int fib1 = helper(n - 1, mem);
    int fib2 = helper(n - 2, mem);
    mem[n] = fib1 + fib2;
    return mem[n];
}

int fib(int n)
{
    // write your code here
    vector<int> mem(n + 1, 0);
    return helper(n, mem);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}