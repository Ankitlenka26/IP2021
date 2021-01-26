#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

// majority element

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int op1 = 0;
        int ele;
        for (int i = 0; i < nums.size(); i++)
        {
            // we assume the initial character to be majority element it will change if op1 reaches to 0 again
            if (op1 == 0)
            {
                op1++;
                ele = nums[i];
            }
            else if (nums[i] == ele)
            {
                op1++; // we increase the count of op1
            }
            else
            {
                op1--; // we dec the count of op1 when we have not encountered the current majority element
            }
        }

        return ele;
    }
};