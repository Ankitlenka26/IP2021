#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// eplanation in the notebook
int cs(int arr[], int n)
{
    // write your code here
    vector<int> dp(n + 1, n + 1);
    dp[n] = 0; // final dest to final dest => 1 rasta
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i + j <= n; j++)
        {
            if (dp[i + j] != n + 1)
            {
                dp[i] = 1 + min(dp[i], dp[i + j]);
            }
        }
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << cs(arr, n) << endl;
}