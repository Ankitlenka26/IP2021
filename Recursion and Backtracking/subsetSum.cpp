#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, int i, int target, string res)
{
    if (target < 0)
    {
        return;
    }
    if (i == arr.size())
    {
        if (target == 0)
        {
            res = res + ".";
            cout << res << endl;
        }
        return;
    }

    // if we add this particular element into the target
    subsetSum(arr, i + 1, target - arr[i], res + to_string(arr[i]) + ", ");
    // if we do not add this particular element into the target
    subsetSum(arr, i + 1, target, res);
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

    int target;
    cin >> target;

    string res = "";

    subsetSum(arr, 0, target, res);

    return 0;
}