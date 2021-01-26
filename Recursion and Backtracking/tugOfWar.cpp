// two subsets with minimum absolute diff

#include <bits/stdc++.h>
using namespace std;

static int mindiff = INT_MAX;
static string ans = "hello";

void solve(vector<int> &arr, int vidx, vector<int> &set1, vector<int> &set2, int soset1, int soset2)
{
    //write your code here

    // base case

    if (vidx == arr.size())
    {
        // cout << soset1 << " " << soset2  ;
        // at this point the size of both sets will be equal
        if (mindiff >= abs(soset1 - soset2))
        {
            mindiff = abs(soset1 - soset2);
            // [1, 3, 6] [2, 4, 5]
            string res = "";
            res += "[";
            for (int i = 0; i < set2.size(); i++)
            {
                if (i == set2.size() - 1)
                {
                    res += to_string(set2[i]) + "]";
                }
                else
                {
                    res += to_string(set2[i]) + ", ";
                }
            }
            res += " ";
            res += "[";
            for (int i = 0; i < set1.size(); i++)
            {
                if (i == set1.size() - 1)
                {
                    res += to_string(set1[i]) + "]";
                }
                else
                {
                    res += to_string(set1[i]) + ", ";
                }
            }
            // cout << res << " ";
            ans = res;
        }

        return;
    }

    // every element has to go in some set and the set sizes should be equal to half of arr size

    // curr element goes to set1
    if (set1.size() < (arr.size() + 1) / 2)
    {
        set1.push_back(arr[vidx]);
        soset1 += arr[vidx];
        solve(arr, vidx + 1, set1, set2, soset1, soset2);
        soset1 -= arr[vidx];
        set1.pop_back();
    }
    // curr element goes to set2
    if (set2.size() < (arr.size() + 1) / 2)
    {
        set2.push_back(arr[vidx]);
        soset2 += arr[vidx];
        solve(arr, vidx + 1, set1, set2, soset1, soset2);
        soset2 -= arr[vidx];
        set2.pop_back();
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> set1;
    vector<int> set2;
    solve(arr, 0, set1, set2, 0, 0);
    cout << ans << endl;
    return 0;
}
