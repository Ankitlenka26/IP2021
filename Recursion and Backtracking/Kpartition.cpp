#include <iostream>
#include <vector>
using namespace std;

static int counter = 0;
void solution(int i, int n, int k, int cones, vector<vector<int>> &ans)
{
    //write your code here
    if (i > n)
    {
        // cout << "Hello" << endl;
        if (cones == k)
        {
            counter++;
            cout << counter << ". ";
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
        return;
    }

    for (int j = 0; j < ans.size(); j++)
    {
        // cout << ans[j].size() << endl ;
        if (ans[j].size() != 0)
        {
            // cout << "Already full set" << endl ;
            ans[j].push_back(i);
            solution(i + 1, n, k, cones, ans);
            // since we hae not added any non empty sets;
            ans[j].pop_back();
        }
        else
        {
            // cout << "Empty set" << endl;
            ans[j].push_back(i);
            solution(i + 1, n, k, cones + 1, ans);
            ans[j].pop_back();
            break;
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(k, vector<int>());
    // for(int i=0 ; i<)
    solution(1, n, k, 0, ans);
    return 0;
}

/*
    cones => count of non empty sets 
    1 => start of number 
    n => end of number 
    k => no of partition
    */