
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int helper(vector<string> words, vector<int> farr, vector<int> score, int idx)
{

    if (idx == words.size())
    {
        return 0;
    }

    // If we do not include the word
    int sno = helper(words, farr, score, idx + 1);
    // If we do include the word

    string word = words[idx];
    bool flag = true; // if we can even use it in the array or not
    int sWord = 0;
    for (int i = 0; i < word.size(); i++)
    {
        char curr = word[i];
        if (farr[curr - 'a'] == 0)
        {
            flag = false;
        }

        farr[curr - 'a']--;
        sWord += score[curr - 'a'];
    }
    int syes = 0;
    if (flag)
    {
        syes = sWord + helper(words, farr, score, idx + 1);
    }

    // Backtracking
    for (int i = 0; i < word.size(); i++)
    {
        char curr = word[i];
        farr[curr - 'a']++;
    }

    return max(sno, syes);
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < words.size(); i++)
    {
        cin >> words[i];
    }

    int letter;
    cin >> letter;
    vector<char> letters(letter);
    vector<int> farr(26);
    for (int i = 0; i < letters.size(); i++)
    {
        cin >> letters[i];
        farr[letters[i] - 'a']++;
    }

    vector<int> score(26);
    for (int i = 0; i < score.size(); i++)
    {
        cin >> score[i];
    }
    int ans = helper(words, farr, score, 0);
    cout << ans << endl;
    return 0;
}