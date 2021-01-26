#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an integer array nums of 2n integers, group these integers into n pairs
 (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is
  maximized. Return the maximized sum.
*/

/*
The simplest solution is to consider every possible set of pairings possible by using the elements of 
the numsnums array. For generating all the possible pairings, we make use of a function permute(nums, current_index).
 This function creates all the possible permutations of the elements of the given array.

To do so, permute takes the index of the current element current_index as one of the arguments. 
Then, it swaps the current element with every other element in the array, lying towards its right, 
so as to generate a new ordering of the array elements. After the swapping has been done, it makes another
 call to permute but this time with the index of the next element in the array. While returning back, we reverse
  the swapping done in the current function call.

Thus, when we reach the end of the array, a new ordering of the array's elements is generated.
 We consider the elements to be taken for the pairings such that the first element of every pair comes
  from the first half of the new array and the second element comes from the last half of the array.
   Thus, we sum up the minimum elements out of all these possible pairings and find out the maximum sum out of them.
*/

class Solution
{
public:
    int arrayPairSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size(); i += 2)
        {
            ans += min(arr[i], arr[i + 1]);
        }

        return ans;
    }
};