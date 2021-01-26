#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// O(mlogn) solution
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (const vector<int> &row : grid)
        { // & it passes the function as a reference hence saves the space

            // if the entire row is positive there is nothing to search
            if (row[n - 1] > 0)
            {
                continue;
            }
            // if the row is mixed of positives and negatives then we can find the no of negatives
            else
            {
                ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
            }
        }

        return ans;
    }
};