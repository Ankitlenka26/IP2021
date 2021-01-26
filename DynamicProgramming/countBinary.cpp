#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std; 

int countBin(int n){
	vector<vector<int>> dp(2 , vector<int>(n+1 , 0));
	dp[0][0] = 0; 
	dp[0][1] = 1; 
	dp[1][0] = 0; 
	dp[1][1] = 1; 
	for(int i=2 ; i<=n ;i++){
		dp[0][i] = dp[1][i-1]; 
		dp[1][i] = dp[0][i-1] + dp[1][i-1];
	} 
	return dp[0][n] + dp[1][n]; 
}

int countBin1(int n){
	if(n==0){
		return 0; 
	}

	int oldCount0 = 1; 
	int oldCount1 = 1; 
	for(int i=2 ; i<= n ;i++){
		int newCount0 = oldCount1; 
		int newCount1 = oldCount0 + oldCount1; 
		oldCount0 = newCount0 ; 
		oldCount1 = newCount1; 
	}

	return oldCount1 + oldCount0;
}

int main(){
	int n ; 
	cin >> n ; 
	cout << countBin(n) << endl; 
	cout << countBin1(n) << endl ;
	return 0; 
}