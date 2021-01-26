#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void wordBreak(string str, string ans, unordered_set<string> &dict)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        string left = str.substr(0, i + 1);
        if (dict.find(left) != dict.end())
        {
            string right = str.substr(i + 1);
            wordBreak(right, ans + left + " ", dict);
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    unordered_set<string> dict;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        dict.insert(temp);
    }
    string sentence;
    cin >> sentence;
    wordBreak(sentence, "", dict);
}
