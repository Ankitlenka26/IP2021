#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an array arr, replace every element in that array with the greatest element among the elements 
to its right, and replace the last element with -1.

After doing so, return the array.
*/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int lastEle = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = max(lastEle, arr[i + 1]);
            lastEle = temp;
        }

        return arr;
    }
};