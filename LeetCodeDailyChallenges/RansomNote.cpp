#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

// Ransom Note

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < magazine.size(); i++)
        {
            m[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (m.find(ransomNote[i]) == m.end())
            {
                return false;
            }
            else if (m[ransomNote[i]] == 1)
            {
                m.erase(ransomNote[i]);
            }
            else
            {
                m[ransomNote[i]]--;
            }
        }

        return true;
    }
};