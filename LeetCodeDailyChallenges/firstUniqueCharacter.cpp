// Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
// First unique character

#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};