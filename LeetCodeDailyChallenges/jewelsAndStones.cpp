// Jewels and stones

/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> s;
        for (int i = 0; i < jewels.size(); i++)
        {
            s.insert(jewels[i]);
        }
        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (s.find(stones[i]) != s.end())
            {
                count++;
            }
        }

        return count;
    }
};