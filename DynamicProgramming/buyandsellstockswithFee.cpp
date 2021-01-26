#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

int helper(vector<int>& arr , int fee){
	if(arr.size() == 0){
		return 0; 
	}

	int obsp -= arr[0]; 
	int ossp = 0; 
	for(int i=1 ; i<arr.size() ; i++){
		int nbsp = 0; 
		int nssp = 0; 

		nbsp = max(obsp , ossp - arr[i]); 
		nssp = max(ossp , obsp + arr[i] - fee); 

		obsp = nbsp ; 
		ossp = nssp; 
	}

	return ossp; 
} 
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}
	int fee ; cin >> fee; 
	int ans = helper(arr,fee); 
	cout << ans << endl; 
	return 0; 
}