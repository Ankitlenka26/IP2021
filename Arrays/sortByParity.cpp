#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Even element at the start and odd element at the last

// Method1 => Comparision function O(NlogN)
bool compare(int x, int y)
{
    return (x % 2 < y % 2);
}

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        sort(A.begin(), A.end(), compare);
        return A;
    }
};

// Method 2 -> partition function STL

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        partition(A.begin(), A.end(), [](int x) {
            return x % 2 == 0;
        });
        return A;
    }
};

// Method 3 -> using two pointer approach

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int i = 0, j = A.size() - 1;
        while (i < j)
        {

            while (i < A.size() && A[i] % 2 == 0)
            {
                i++;
            }
            while (j >= 0 && A[j] % 2 == 1)
            {
                j--;
            }

            if (i < j && A[i] % 2 == 1 && A[j] % 2 == 0)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++, j--;
            }
        }

        return A;
    }
};