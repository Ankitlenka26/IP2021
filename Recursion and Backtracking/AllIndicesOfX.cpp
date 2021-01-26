#include <iostream>
#include <vector>
using namespace std;

vector<int> *allIndices(vector<int> arr, int x, int idx, int fsf)
{
    if (idx == arr.size())
    {
        vector<int> *res = new vector<int>(fsf);
        return res;
    }

    if (arr[idx] == x)
    {
        vector<int> *iarr = allIndices(arr, x, idx + 1, fsf + 1);
        iarr->at(fsf) = idx;
        return iarr;
    }
    else
    {
        vector<int> *iarr = allIndices(arr, x, idx + 1, fsf);
        return iarr;
    }
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

    int x;
    cin >> x;

    vector<int> *ans = allIndices(arr, x, 0, 0);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << endl;
    }

    return 0;
}