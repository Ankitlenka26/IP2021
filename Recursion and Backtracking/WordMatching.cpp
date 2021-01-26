#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solution(string str, string pattern, unordered_map<char, string> &m, string op)
{
    // base case

    if (pattern.size() == 0)
    {
        if (str.size() == 0)
        {
            // p -> graph, e -> trees, .
            unordered_set<char> s;
            for (int i = 0; i < op.size(); i++)
            {
                if (s.find(op[i]) == s.end())
                {
                    cout << op[i] << " -> " << m[op[i]] << ", ";
                }
                s.insert(op[i]);
            }

            cout << ".";
            cout << endl;
        }
        return;
    }

    char ch = pattern[0];
    string rem = pattern.substr(1);
    if (m.find(ch) != m.end())
    {
        string previousMapping = m[ch];
        if (str.size() >= previousMapping.size())
        {
            string left = str.substr(0, previousMapping.size());
            string right = str.substr(previousMapping.size());
            if (left == previousMapping)
            {
                solution(right, rem, m, op);
            }
        }
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            string left = str.substr(0, i + 1);
            string right = str.substr(i + 1);
            m[ch] = left;
            solution(right, rem, m, op);
            m.erase(ch);
        }
    }

    return;
}
int main()
{
    string str, pattern;
    cin >> str >> pattern;
    unordered_map<char, string> m;
    solution(str, pattern, m, pattern);
    return 0;
}
