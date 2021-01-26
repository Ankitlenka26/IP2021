
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void goldMine(vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &visited, vector<int> &gold)
{
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 0 || visited[i][j] == true)
    {
        return;
    }
    // Mark visited and add the gold
    visited[i][j] = true;
    gold.push_back(arr[i][j]);
    // Go all directions
    goldMine(arr, i - 1, j, visited, gold);
    goldMine(arr, i, j + 1, visited, gold);
    goldMine(arr, i, j - 1, visited, gold);
    goldMine(arr, i + 1, j, visited, gold);
    return;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxGold = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            if (arr[i][j] != 0 && visited[i][j] == false)
            {
                vector<int> gold;
                goldMine(arr, i, j, visited, gold);
                for (auto val : gold)
                {
                    sum += val;
                }
                maxGold = max(maxGold, sum);
            }
        }
    }

    cout << maxGold << endl;
    return 0;
}