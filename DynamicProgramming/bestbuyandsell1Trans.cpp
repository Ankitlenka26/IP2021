#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

int helper(vector<int>& arr){
	int leastPriceSoFar = INT_MAX; 
	int overallProf = 0; 
	int profIfSoldToday = 0; 
	for(int i=0;i<arr.size();i++){
		if(arr[i] < leastPriceSoFar){
			leastPriceSoFar = arr[i]; 
		}

		profIfSoldToday = arr[i] - leastPriceSoFar ; 
		overallProf = max(overallProf,profIfSoldToday); 
	}

	return overallProf; 
}
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}

	int ans = helper(arr); 
	cout << ans << endl; 
	return 0; 
}