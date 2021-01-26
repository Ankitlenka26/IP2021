#include<iostream>
#include<vector>
using namespace std; 

bool helper(vector<int>& arr , int n , int tar){
    vector<vector<bool>> dp(n+1 , vector<bool>(tar+1, false)); 
    for(int i=0 ;i<= n ; i++){
        for(int j=0 ; j<=tar ; j++){
            if(i==0 && j==0){
                // trivial cell 
                dp[i][j] = true; 
            }else if(i==0){
                // first row 
                dp[i][j] = false;
            }else if(j==0){
                // first column 
                dp[i][j] = true;
            }else{
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]); 
                }else{
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }
    }
    
    return dp[n][tar]; 
}

int main(){
    int n ; 
    cin >> n ;
    vector<int> arr(n);
    for(int i=0;i<n ;i++){
        cin >> arr[i];
    }
    int tar;
    cin >> tar; 
    
    bool ans = helper(arr,n,tar); 
    if(ans){
        cout << "true" << endl;
    }else{
        cout << "false" << endl ;
    }
    
    return 0;
}