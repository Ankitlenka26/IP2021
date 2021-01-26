#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> helper(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> brem;
        brem.push_back("");
        return brem;
    }
    vector<string> path;
    for (int ms = 1; ms <= dc - sc; ms++)
    {
        vector<string> hpaths = helper(sr, sc + ms, dr, dc);
        for (string hpath : hpaths)
        {
            path.push_back("h" + to_string(ms) + hpath);
        }
    }

    for (int ms = 1; ms <= dr - sr; ms++)
    {
        vector<string> vpaths = helper(sr + ms, sc, dr, dc);
        for (string vpath : vpaths)
        {
            path.push_back("v" + to_string(ms) + vpath);
        }
    }
    for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++)
    {
        vector<string> dpaths = helper(sr + ms, sc + ms, dr, dc);
        for (string dpath : dpaths)
        {
            path.push_back("d" + to_string(ms) + dpath);
        }
    }

    return path;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = helper(1, 1, n, m);
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