#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str)
{
    for (int i = 0; i < (1 << str.size()); i++)
    {
        string t;
        int count = 0;
        // we will have to analyse from the bits from the MSB to LSB
        for (int j = 0; j < str.size(); j++)
        {
            int b = str.size() - 1 - j;
            char ch = str[j];
            if ((i & (1 << b)) == 0)
            {
                if (count == 0)
                {
                    t = t + ch;
                }
                else
                {
                    t = t + to_string(count);
                    t = t + ch;
                    count = 0;
                }
            }
            else
            {
                count++;
            }
        }

        if (count > 0)
        {
            t = t + to_string(count);
        }

        cout << t << endl;
    }

    return;
}

int main()
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}