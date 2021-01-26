
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return;
}

bool isValid(vector<vector<int>> &board, int row, int col, int val)
{
    // is column valid

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == val)
            return false;
    }
    // is row valid
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[row][i] == val)
            return false;
    }
    // is submatrix valid
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[sr + i][sc + j] == val)
                return false;
        }
    }

    return true;
}

void sudoku(vector<vector<int>> &board, int i, int j)
{
    if (i == board.size())
    {
        // cout << "hey" << endl ;
        display(board);
        return;
    }

    int ni = 0;
    int nj = 0;
    if (j == board[0].size() - 1)
    {
        ni = i + 1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j + 1;
    }

    if (board[i][j] != 0)
    {
        sudoku(board, ni, nj);
    }
    else
    {
        for (int op = 1; op <= 9; op++)
        {
            if (isValid(board, i, j, op))
            {
                board[i][j] = op;
                sudoku(board, ni, nj);
                board[i][j] = 0;
            }
        }
    }

    return;
}

int main()
{
    // int n ;
    // cin >> n ;
    vector<vector<int>> board(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    // display(board);
    sudoku(board, 0, 0);
    return 0;
}