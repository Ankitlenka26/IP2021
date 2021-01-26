#include <iostream>
#include <vector>
using namespace std;

int helper(int n, vector<int> &mem)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }

    int s1 = helper(n - 1, mem);
    int s2 = helper(n - 2, mem);
    int s3 = helper(n - 3, mem);
    mem[n] = s1 + s2 + s3;
    return mem[n];
}

int cs(int n)
{
    // write your code here
    vector<int> mem(n + 1, 0);
    return helper(n, mem);
}

int main()
{
    int n;
    cin >> n;
    cout << cs(n) << endl;
}