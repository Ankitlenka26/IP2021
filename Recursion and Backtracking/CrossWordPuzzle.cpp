#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void displayPuzzle(vector<vector<char>> &arr)
{
    //  cout << "hey diplay" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return;
}

bool canPlaceWordHorizontally(vector<vector<char>> &arr, string word, int i, int j)
{
    // can place + on both left and right side or the word should be placed on the extremes

    // left side hai aur vahan kuch aur pada hai (+ ke alava)
    if (j - 1 >= 0 && arr[i][j - 1] != '+')
    {
        return false;
    }
    // right side hai aur vahan kuch aur pada hai
    else if (j + word.size() < arr[0].size() && arr[i][j + word.size()] != '+')
    {
        return false;
    }

    // yahan tak aagye to word perfect fit hai

    // char to char match kiya word ko aur ya to vahi char ho ya fir _ ho
    for (int jj = 0; jj < word.size(); jj++)
    {

        if (jj + j >= arr[0].size())
        {
            return false;
        }

        if (arr[i][j + jj] == '-' || arr[i][j + jj] == word[jj])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool canPlaceWordVertically(vector<vector<char>> &arr, string word, int i, int j)
{
    // can place + on both UP and DOWN side or the word should be placed on the extremes

    // Up side hai aur vahan kuch aur pada hai (+ ke alava)
    if (i - 1 >= 0 && arr[i - 1][j] != '+')
    {
        return false;
    }
    // Down side hai aur vahan kuch aur pada hai
    else if (i + word.size() < arr.size() && arr[i + word.size()][j] != '+')
    {
        return false;
    }

    // yahan tak aagye to word perfect fit hai
    // char to char match kiya word ko aur ya to vahi char ho ya fir _ ho
    for (int ii = 0; ii < word.size(); ii++)
    {

        if (ii + i >= arr.size())
        {
            return false;
        }

        if (arr[i + ii][j] == '-' || arr[i + ii][j] == word[ii])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

vector<bool> placeWordHorizontally(vector<vector<char>> &arr, string word, int i, int j)
{
    vector<bool> wePlaced(word.size(), false);
    for (int jj = 0; jj < word.size(); jj++)
    {
        if (arr[i][j + jj] == '-')
        {
            arr[i][j + jj] == word[jj];
            wePlaced[jj] = true;
        }
    }

    return wePlaced;
}

void unplaceWordHorizontally(vector<vector<char>> &arr, vector<bool> &wePlaced, int i, int j)
{
    for (int jj = 0; jj <= wePlaced.size(); jj++)
    {
        if (wePlaced[jj] == true)
        {
            arr[i][j + jj] = '-';
        }
    }

    return;
}

vector<bool> placeWordVertically(vector<vector<char>> &arr, string word, int i, int j)
{
    vector<bool> wePlaced(word.size(), false);
    for (int ii = 0; ii < word.size(); ii++)
    {
        if (arr[i + ii][j] == '-')
        {
            arr[i + ii][j] == word[ii];
            wePlaced[ii] = true;
        }
    }
    return wePlaced;
}

void unplaceWordVertically(vector<vector<char>> &arr, vector<bool> &wePlaced, int i, int j)
{
    for (int ii = 0; ii <= wePlaced.size(); ii++)
    {
        if (wePlaced[ii] == true)
        {
            arr[i + ii][j] = '-';
        }
    }

    return;
}

void crossword(vector<vector<char>> &arr, vector<string> &words, int idx)
{

    if (idx == words.size())
    {
        displayPuzzle(arr);
        return;
    }
    string word = words[idx];

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '-' || arr[i][j] == word[0])
            {
                if (canPlaceWordHorizontally(arr, word, i, j))
                {
                    vector<bool> wePlaced = placeWordHorizontally(arr, word, i, j);
                    crossword(arr, words, idx + 1);
                    // displayPuzzle(arr);
                    unplaceWordHorizontally(arr, wePlaced, i, j);
                }
                if (canPlaceWordVertically(arr, word, i, j))
                {
                    vector<bool> wePlaced = placeWordVertically(arr, word, i, j);
                    crossword(arr, words, idx + 1);
                    // displayPuzzle(arr);
                    unplaceWordVertically(arr, wePlaced, i, j);
                }
            }
        }
    }

    return;
}

int main()
{
    vector<vector<char>> arr(10, vector<char>(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    crossword(arr, words, 0);
    return 0;
}