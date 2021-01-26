#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

int helper(vector<int>& arr){
	int bd =0 ; // buying date  
	int sd =0;  // selling date 
	int profit =0; 
	for(int i=0 ;i<arr.size()-1; i++){
		if(arr[i] <= arr[i+1]){
			sd++;
		}else{
			profit += arr[sd] - arr[bd]; 
			bd = sd = i+1;
		}
	}
	profit += arr[sd] - arr[bd];
	return profit; 
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