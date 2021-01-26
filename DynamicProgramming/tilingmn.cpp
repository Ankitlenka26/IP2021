#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std ; 

int main(){
	int n , m ; 
	cin >> n >> m ; 

	vector<int> dp(n+1); 
	for(int i=0 ;i<=n ;i++){
		if(i<m){
			dp[i] = 1; 
		}else if(i==m){
			dp[i] = 2;
		}else{
			dp[i] = dp[i-1] + dp[i-m];  
		}
	}

	cout << dp[n] << endl ;

	return 0; 
}