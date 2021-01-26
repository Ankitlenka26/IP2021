//Minimum Cost to Move Chips to The Same Position

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.
*/

class Solution
{
public:
    int minCostToMoveChips(vector<int> &arr)
    {
        /*
         if we go from a even position to a even position or a 
         odd position to an odd position there is no cost required . 
         but if we go from odd to even or from even to odd there is some cost
         required . 
         
         So , we will check which count is less(odd or even) and that will be the answer
        */
        int oddcount = 0, evencount = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 0)
            {
                evencount++;
            }
            else
            {
                oddcount++;
            }
        }

        return evencount > oddcount ? oddcount : evencount;
    }
};