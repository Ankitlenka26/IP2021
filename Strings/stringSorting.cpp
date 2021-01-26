#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Sort a list of strings
bool compare(string i, string j)
{
    return (i.length() < j.length());
}
int main()
{
    int n;
    cin >> n;
    string s[100];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, compare); // by default it will be based on the lexographical sorting
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}