#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void floodfill(vector<vector<int>> &arr, int row, int col, string psf, vector<vector<bool>> vis)
{
    if (row < 0 || col < 0 || row >= arr.size() || col >= arr[0].size() || arr[row][col] == 1 || vis[row][col] == true)
    {
        return;
    }
    if (row == arr.size() - 1 && col == arr[0].size() - 1)
    {
        cout << psf << endl;
        return;
    }

    vis[row][col] = true;
    floodfill(arr, row - 1, col, psf + 't', vis);
    floodfill(arr, row, col - 1, psf + 'l', vis);
    floodfill(arr, row + 1, col, psf + 'd', vis);
    floodfill(arr, row, col + 1, psf + 'r', vis);
    vis[row][col] = false;

    return;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    floodfill(arr, 0, 0, "", vis);
    return 0;
}