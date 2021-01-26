#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount 
for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] 
where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive 
any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop 
considering the special discount.
*/

class Solution
{
public:
    vector<int> finalPrices(vector<int> &A)
    {
        // this question can easily be solved using brute force O(N2) approach
        // order matters so we cannot sort the array
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i)
        {
            while (stack.size() && A[stack.back()] >= A[i])
            {
                A[stack.back()] -= A[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return A;
    }
};