#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int helper(vector<vector<int>>& arr , int n , int c){
	// first row will be same as arr matrix 
	vector<vector<int>> dp(n , vector<int>(c)); 
	int least = INT_MAX; 
	int sleast = INT_MAX; 
	for(int i=0 ;i<c ;i++){
		dp[0][i] = arr[0][i];
		if(dp[0][i] <= least){
			sleast = least;
			least = dp[0][i];
		}else if(dp[0][i] <= sleast){
			sleast = dp[0][i]; 
		}
	}

	for(int i=1;i<n ;i++){
		int nleast = INT_MAX; 
		int nsleast = INT_MAX; 
		for(int j=0 ; j<c ; j++){
			if(dp[i-1][j] == least){
				dp[i][j] = sleast + arr[i][j];
			}else{
				dp[i][j] = least + arr[i][j]; 
			}
    		if(dp[i][j] <= nleast){
    			nsleast = nleast;
    			nleast = dp[i][j];
    		}else if(dp[i][j] <= nsleast){
    			nsleast = dp[i][j]; 
    		}
			
		}
		least = nleast; 
		sleast = nsleast;
	}

	return least;
} 

int main(){
	int n , c ; 
	cin >> n >> c ; 
	vector<vector<int>> arr(n , vector<int>(c)); 
	for(int i=0 ;i<n ; i++){
		for(int j=0; j<c ; j++){
			cin >> arr[i][j]; 
		}
	}

	int ans = helper(arr , n , c); 
	cout << ans << endl ;
	return 0; 
}