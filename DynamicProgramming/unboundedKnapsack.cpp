#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

int helper(vector<int>& w , vector<int>& val , int n , int weight){
	vector<int> dp(weight+1,0); 
	for(int i=1 ; i<= weight ; i++){
		for(int j=0 ; j<n ; j++){
			if(w[j] <= i){
				dp[i] = max(dp[i] , val[j] + dp[i-w[j]]); 
			}
		}
	}
	return dp[weight]; 
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