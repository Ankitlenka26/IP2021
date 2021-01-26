#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

int helper(vector<int>& arr , int n , int target){
	vector<int> dp(target+1 , 0); 
	dp[0] = 1; 
	for(int i=0 ;i<arr.size() ; i++){
		for(int j= arr[i] ; j<= target ; j++){
			dp[j] += dp[j-arr[i]]; 
		}
	}

	return dp[target]; 
}
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}
	int target; 
	cin >> target; 

	cout << helper(arr ,n , target) << endl; 
	return 0; 
}