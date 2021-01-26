#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSubs(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string rems = s.substr(1);
    // If we add char to the list
    printSubs(rems, ans + ch);
    // if we do not add char to the list
    printSubs(rems, ans + "");

    return;
}

int main()
{
    string s;
    cin >> s;
    printSubs(s, "");
    return 0;
}