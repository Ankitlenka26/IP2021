
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void abbreviations(string s, string ssf, int count)
{
    // basecase
    if (s.size() == 0)
    {
        if (count == 0)
        {
            cout << ssf << endl;
        }
        else
        {
            cout << ssf + to_string(count) << endl;
        }

        return;
    }
    char ch = s[0];
    string rem = s.substr(1);
    // if we include the current char
    if (count == 0)
    {
        abbreviations(rem, ssf + ch, count);
    }
    else
    {
        abbreviations(rem, ssf + to_string(count) + ch, 0);
    }
    // if we do no include the current char
    abbreviations(rem, ssf, count + 1);
}

int main()
{
    string s;
    cin >> s;
    abbreviations(s, "", 0);
    return 0;
}