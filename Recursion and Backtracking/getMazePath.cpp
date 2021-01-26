#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> helper(int sr, int sc, int dr, int dc)
{
    // Base case
    if (sr == dr - 1 && sc == dc - 1)
    {
        vector<string> brem;
        brem.push_back("");
        return brem;
    }
    else if (sr >= dr || sc >= dc)
    {
        vector<string> brem;
        return brem;
    }
    //  Recursion
    // to right
    vector<string> path1 = helper(sr, sc + 1, dr, dc);
    // to down
    vector<string> path2 = helper(sr + 1, sc, dr, dc);

    vector<string> path;
    for (int i = 0; i < path1.size(); i++)
    {
        path.push_back("h" + path1[i]);
    }
    for (int i = 0; i < path2.size(); i++)
    {
        path.push_back("v" + path2[i]);
    }
    // Return Statement

    return path;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = helper(0, 0, n, m);
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