#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    // base case
    if (s.size() == 0)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    // write your code here
    char ch = s[0];
    string ros = s.substr(1);
    vector<string> rems = gss(ros);
    vector<string> mres;
    for (int i = 0; i < rems.size(); i++)
    {
        mres.push_back("" + rems[i]);
    }
    for (int i = 0; i < rems.size(); i++)
    {
        mres.push_back(ch + rems[i]);
    }

    return mres;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = gss(s);
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