
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int x[] = {-2, -1, +1, +2, +2, +1, -1, -2};
int y[] = {+1, +2, +2, +1, -1, -2, -2, -1};

void knightTour(vector<vector<int>> &chess, int row, int col, int count)
{
    // we are either out of bounds or we are visiting the chessBoard for the repeated time
    if (row < 0 || col < 0 || row >= chess.size() || col >= chess[0].size() || chess[row][col] != 0)
    {
        return;
    }

    // Base case to show the chess
    if (count == chess.size() * chess.size())
    {
        chess[row][col] = chess.size() * chess.size();
        for (int i = 0; i < chess.size(); i++)
        {
            for (int j = 0; j < chess[0].size(); j++)
            {
                cout << chess[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // recur
    for (int i = 0; i < 8; i++)
    {
        chess[row][col] = count;
        knightTour(chess, row + x[i], col + y[i], count + 1);
        chess[row][col] = 0;
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    int row, col;
    cin >> row >> col;
    knightTour(chess, row, col, 1);

    return 0;
}