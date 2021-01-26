#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isQueenSafe(vector<vector<int>> &chess, int row, int col)
{

    // vertical safe
    for (int i = row - 1; i >= 0; i--)
    {
        if (chess[i][col] == 1)
        {
            return false;
        }
    }

    // left diagonal safe
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // right diagonal safe
    for (int i = row - 1, j = col + 1; i >= 0 && j < chess[0].size(); i--, j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void NQueens(vector<vector<int>> &chess, string qsf, int row)
{
    if (row == chess.size())
    {
        cout << qsf + "." << endl; // if the queen configuration is correct it will hit the base case and get printed
        return;
    }

    for (int col = 0; col < chess[0].size(); col++)
    {

        // can only enter if the queen is not attacked by anybody
        if (isQueenSafe(chess, row, col))
        {
            chess[row][col] = 1; // to set the queen at that position
            NQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0; // to unset the queen at that position
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    NQueens(chess, "", 0);
    return 0;
}