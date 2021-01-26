#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std ; 
ll partitionSubsets(int n , int k){
	vector<vector<ll>> dp(k+1 , vector<int>(n+1,0)); 
	dp[0][0] = 1;
	for(int i=1 ;i<=k ; i++){
		for(int j=1; j<=n ; j++){
			dp[i][j] = (i)*(dp[i][j-1]) + dp[i-1][j-1]; 
		}
	}
	return dp[k][n];
}
int main(){
	int n , k ; 
	ll ans = partitionSubsets(n,k); 
	cout << ans << endl ;
	return 0; 
}