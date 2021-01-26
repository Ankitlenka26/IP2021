#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++, j--;
    }

    return true;
}
void sol(string s, string asf)
{
    if (s.size() == 0)
    {
        cout << asf << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string subs = s.substr(0, i + 1);
        string rem = s.substr(i + 1);
        if (isPalindrome(subs))
        {
            sol(rem, asf + "(" + subs + ") ");
        }
    }

    return;
}

int main()
{
    string s;
    cin >> s;
    string asf = "";
    sol(s, asf);
    return 0;
}