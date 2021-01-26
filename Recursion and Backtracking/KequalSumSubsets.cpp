#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> &arr, int vidx, int n, int k, vector<int> &subsetSum, int ssssf, vector<vector<int>> &ans, int sum)
{

    if (vidx == arr.size())
    {
        if (ssssf == k)
        {
            bool flag = true;
            for (int i = 0; i < subsetSum.size() - 1; i++)
            {
                if (subsetSum[i] != subsetSum[i + 1])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                // print the subsets
                for (const vector<int> &row : ans)
                {
                    cout << "[";
                    for (int i = 0; i < row.size(); i++)
                    {
                        if (i == row.size() - 1)
                        {
                            cout << row[i];
                        }
                        else
                        {
                            cout << row[i] << ", ";
                        }
                    }
                    cout << "] ";
                }
                cout << endl;
            }
        }

        return;
    }
    for (int i = 0; i < ans.size(); i++)
    {

        if (ans[i].size() != 0)
        {
            // cout << "Already full set" << endl ;
            ans[i].push_back(arr[vidx]);
            subsetSum[i] += arr[vidx];
            solution(arr, vidx + 1, n, k, subsetSum, ssssf, ans, sum);
            subsetSum[i] -= arr[vidx];
            ans[i].pop_back();
        }
        else
        {
            ans[i].push_back(arr[vidx]);
            subsetSum[i] += arr[vidx];
            solution(arr, vidx + 1, n, k, subsetSum, ssssf + 1, ans, sum);
            subsetSum[i] -= arr[vidx];
            ans[i].pop_back();
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int k;
    cin >> k;
    // if k is equal to 1, then whole array is your answer
    if (k == 1)
    {
        cout << "[";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ", ";
        }
        cout << "]";
    }
    //if there are more subsets than no. of elements in array or sum of all elements is not divisible by k
    else if (k > n || sum % k != 0)
    {
        // non empty subsets cannot be more than n
        // if the sum is not divisible by k then it is not possible
        cout << "-1" << endl;
    }
    else
    {
        vector<int> subsetSum(k);
        vector<vector<int>> ans(k, vector<int>());
        solution(arr, 0, n, k, subsetSum, 0, ans, sum);
    }

    return 0;
}