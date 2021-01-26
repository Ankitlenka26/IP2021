#include <iostream>
#include <string>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string s, string asf)
{
    // write your code here
    // Base case
    if (s.size() == 0)
    {
        cout << asf << endl;
        return;
    }

    //we have to use any one of the array characters
    char ch = s[0];
    string rems = s.substr(1);
    string curr = codes[ch - '0'];
    // use each of the characters in the current string
    for (int i = 0; i < curr.size(); i++)
    {
        printKPC(rems, asf + curr[i]);
    }

    return;
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
}