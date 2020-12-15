#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr) / sizeof(int);
    // Search - > find function inside STL library
    int key;
    cin >> key;

    auto it = find(arr, arr + n, key);
    // it will provide us with address at which the key is located
    cout << it << endl;

    int index = it - arr;
    cout << index << endl;

    if (index < n)
    {
        cout << "key is present" << endl;
    }
    else
    {
        cout << "Key is not present in the array" << endl;
    }

    return 0;
}