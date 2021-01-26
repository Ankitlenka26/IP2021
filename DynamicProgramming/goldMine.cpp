#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int helper(vector<vector<int>> &arr, int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    // fill the last column
    for (int i = 0; i < row; i++)
    {
        dp[i][col - 1] = arr[i][col - 1];
    }
    // fill the prev columns now
    for (int i = col - 2; i >= 0; i--)
    {
        for (int j = 0; j < row; j++)
        {
            if (j == 0)
            {
                dp[j][i] = arr[j][i] + max(dp[j][i + 1], dp[j + 1][i + 1]);
            }
            else if (j == row - 1)
            {
                dp[j][i] = arr[j][i] + max(dp[j][i + 1], dp[j - 1][i + 1]);
            }
            else
            {
                dp[j][i] = arr[j][i] + max(dp[j][i + 1], max(dp[j - 1][i + 1], dp[j + 1][i + 1]));
            }
        }
    }
    // ans  is contained in the first col of dp array
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        ans = max(ans, dp[i][0]);
    }

    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = helper(arr, r, c);
    cout << ans << endl;
    return 0;
}
