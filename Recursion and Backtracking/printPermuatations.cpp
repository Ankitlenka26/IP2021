#include <iostream>
#include <string>
using namespace std;

void printPermutations(string s, string asf)
{
    if (s.size() == 0)
    {
        cout << asf << endl;
    }
    // write your code here
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        string lrem = s.substr(0, i);     // jis char ko nikal liya hai uske left ki string
        string rrem = s.substr(i + 1);    // jis char ko nikal liya hai uske right ki string
        string rem = lrem + rrem;         // bachi hui string jispar recursion lagana hai
        printPermutations(rem, asf + ch); // vo char ko ans mai dala aur baaki sab ke liye permutate kiya
    }

    return;
}

int main()
{
    string str;
    cin >> str;
    printPermutations(str, "");
}