#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given two integer arrays of equal length target and arr.

In one step, you can select any non-empty sub-array of arr and reverse it. You are allowed to make any number of steps.

Return True if you can make arr equal to target, or False otherwise
*/

class Solution
{
public:
    bool canBeEqual(vector<int> &t, vector<int> &a)
    {
        // one permutation to another permutation can be formed by reversing subarrays
        // that means we just have to check
        sort(t.begin(), t.end());
        sort(a.begin(), a.end());
        return (t == a);
    }
};
