
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void nqueens(vector<vector<int>> &board, vector<bool> column, vector<bool> ndiag, vector<bool> rdiag, string psf, int row)
{
    if (row == board.size())
    {
        cout << psf + "." << endl;
        return;
    }

    for (int col = 0; col < column.size(); col++)
    {
        if (column[col] == false && ndiag[row + col] == false && rdiag[row - col + board.size() - 1] == false)
        {
            board[row][col] = 1;
            column[col] = true;
            ndiag[row + col] = true;
            rdiag[row - col + board.size() - 1] = true;
            nqueens(board, column, ndiag, rdiag, psf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            board[row][col] = 0;
            column[col] = false;
            ndiag[row + col] = false;
            rdiag[row - col + board.size() - 1] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<bool> col(n, false);
    vector<bool> ndiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);
    nqueens(board, col, ndiag, rdiag, "", 0);
    return 0;
}