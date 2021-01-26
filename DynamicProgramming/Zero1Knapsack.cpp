#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

int helper(vector<int>& w , vector<int>& val , int n , int weight){
	vector<vector<int>> dp(n+1 , vector<int>(weight+1,0)); 
	for(int i=1 ;i<= n ; i++){
		for(int j=1 ; j<=weight ; j++){
			    if(w[i-1] <= j){
			    	dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-w[i-1]]); 
			    }else{
			    	dp[i][j] = dp[i-1][j]; 
			    }
		}
	}

	return dp[n][weight]; 
}
int main(){
	int n ; 
	cin >> n ; 
	vector<int> w(n) , val(n); 
	for(int i=0 ;i<n ;i++){
		cin >> val[i]; 
	}
    for(int i=0 ;i<n ;i++){
		cin >> w[i]; 
	}
	int weight; 
	cin >> weight; 
	cout << helper(w , val , n , weight) << endl; 
	return 0; 
}