
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void dfs(int x, int n)
{
    if (x > n)
    {
        return;
    }

    cout << x << endl;
    for (int i = 0; i <= 9; i++)
    {
        int temp = x * 10 + i;
        dfs(temp, n);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
    {
        dfs(i, n);
    }
    return 0;
}