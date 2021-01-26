#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void palindromicPerm(int i, int n, map<char, int> &freqm, char oddc, string asf)
{
    // base case
    if (i > n)
    {
        string res = asf;
        if (oddc != '0')
        {
            res += oddc;
        }
        reverse(asf.begin(), asf.end());
        res += asf;
        cout << res << endl;
        return;
    }

    // we will go to those elements whose freq is more than one
    for (auto it : freqm)
    {
        char currch = it.first;
        int freq = it.second;
        if (freq > 0)
        {
            freqm[currch]--;
            palindromicPerm(i + 1, n, freqm, oddc, asf + currch);
            freqm[currch]++;
        }
    }

    return;
}
int main()
{
    string s;
    cin >> s;
    map<char, int> freqm;
    for (int i = 0; i < s.size(); i++)
    {
        freqm[s[i]]++;
    }

    char oddc = '0'; // odd char that is present;
    int odds = 0;    // no of char with odd freq;
    int len = 0;     // length of the half string
    for (auto it : freqm)
    {
        if (it.second % 2 == 1)
        {
            // odd char
            oddc = it.first;
            odds++;
        }

        freqm[it.first] = (it.second) / 2;
        len += freqm[it.first];
    }

    // for(auto it : freqm){
    //     cout << it.first << " " << it.second;
    // }
    if (odds > 1)
    {
        cout << -1 << endl;
    }
    else
    {
        palindromicPerm(1, len, freqm, oddc, "");
    }
    return 0;
}