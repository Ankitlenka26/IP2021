#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.
*/

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &arr)
    {
        int i = 0; // it will carry the even elements and only go at even indices
        int j = 1; // it will carry the odd elements and only go at odd indices
        int n = arr.size();

        while (i < n && j < n)
        {
            // i is at correct position , move forward
            while (i < n && arr[i] % 2 == 0)
            {
                i += 2;
            }
            // j is at correct position , move forward
            while (j < n && arr[j] % 2 == 1)
            {
                j += 2;
            }

            // i and j are both in wrong positions , swap the values and move forward
            if (i < n && j < n && arr[i] % 2 == 1 && arr[j] % 2 == 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i += 2;
                j += 2;
            }
        }

        return arr;
    }
};