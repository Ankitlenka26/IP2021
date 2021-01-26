// A Program to check if strings are rotations of each other or not
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // to have a string asa rotation of another string then we just have to check if one of the strings is the substring of the 2 times the other string
    s1 += s1;
    if (s1.find(s2) != string::npos)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    return 0;
}