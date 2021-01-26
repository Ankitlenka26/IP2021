// Split the binary string into substrings with equal number of 0s and 1s

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    int freq = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            freq++;
        }
        else
        {
            freq--;
        }
        if (freq == 0)
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}