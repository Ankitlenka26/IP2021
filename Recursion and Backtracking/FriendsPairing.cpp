#include <iostream>
#include <vector>
#include <string>

using namespace std;
static int counter = 1;
void solution(int i, int n, vector<bool> &used, string asf)
{
    if (i > n)
    {
        cout << to_string(counter) + "." + asf << endl;
        counter++;
        return;
    }

    //if the number is already included we just pass on
    if (used[i] == true)
    {
        solution(i + 1, n, used, asf);
    }
    else
    {
        used[i] = true;
        // if we only use this number
        solution(i + 1, n, used, asf + "(" + to_string(i) + ") ");
        for (int j = i + 1; j <= n; j++)
        {
            if (used[j] == false)
            {
                used[j] = true;
                solution(i + 1, n, used, asf + "(" + to_string(i) + "," + to_string(j) + ") ");
                used[j] = false;
            }
        }
        used[i] = false;
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> used(n, false);
    solution(1, n, used, "");
    return 0;
}