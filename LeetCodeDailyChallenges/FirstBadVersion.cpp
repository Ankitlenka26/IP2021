// First Bad Version
// Is bad version is already defined for you

/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
class Solution
{
public:
    //     Simple Binary Searh can be used
    int firstBadVersion(int n)
    {
        int i = 1, j = n;

        int mid = (j - i) / 2 + i;
        int ans = -1;
        while (i <= j)
        {
            mid = (j - i) / 2 + i;
            if (isBadVersion(mid))
            {
                ans = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        return ans;
    }
};