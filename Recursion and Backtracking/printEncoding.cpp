#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printEncoding(string s, string asf)
{
    // write your code here
    if (s.size() == 0)
    {
        cout << asf << endl;
        return;
    }
    if (s[0] == '0')
    {
        return;
    }

    char ch = (char)(96 + (int)(s[0] - '0'));
    string rem = s.substr(1);
    printEncoding(rem, asf + ch);
    int x = stoi(s.substr(0, 2));
    if (s.size() > 1 && x <= 26)
    {
        string rem = s.substr(2);
        char ch = (char)(96 + x);
        printEncoding(rem, asf + ch);
    }

    return;
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}