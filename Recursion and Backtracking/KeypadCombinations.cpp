// [tv, tw, tx, uv, uw, ux]
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<string> helper(string s, unordered_map<char, string> m)
{
    // base case
    if (s.size() == 0)
    {
        vector<string> temp;
        temp.push_back("");
        return temp;
    }
    // recursive
    char ch = s[0];
    string ros = s.substr(1);
    vector<string> rem = helper(ros, m);
    vector<string> ans;
    string temp = m[ch];
    for (int j = 0; j < temp.size(); j++)
    {
        for (int i = 0; i < rem.size(); i++)
        {
            ans.push_back(temp[j] + rem[i]);
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    unordered_map<char, string> m;
    m['0'] = ".;";
    m['1'] = "abc";
    m['2'] = "def";
    m['3'] = "ghi";
    m['4'] = "jkl";
    m['5'] = "mno";
    m['6'] = "pqrs";
    m['7'] = "tu";
    m['8'] = "vwx";
    m['9'] = "yz";

    vector<string> ans = helper(s, m);
    int cnt = 0;
    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}