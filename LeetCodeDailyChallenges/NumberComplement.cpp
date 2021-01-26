// Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
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
    int findComplement(int num)
    {
        int rmsb = (num & (-1 * num)), mask, number = ~num;

        while (num)
        {
            num -= rmsb;
            mask = rmsb;
            rmsb = (num & (-1 * num));
        }

        mask--;
        mask = (mask << 1) + 1;

        return (mask & number);
    }
}