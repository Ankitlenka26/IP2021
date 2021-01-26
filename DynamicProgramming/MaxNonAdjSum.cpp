#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long int
using namespace std; 

int helper(vector<int>& arr , int n){
	int include =0 ; 
	int exclude =0 ; 
	if(n==0){
		return 0; 
	}
	include  = arr[0] ; 
	exclude = 0; 
	for(int i=1 ;i<n ;i++){
		int Ninclude = arr[i] + exclude; 
		int Nexclude = max(include,exclude);
		include = Ninclude; 
		exclude = Nexclude; 
	}

	return max(include,exclude); 
}
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ; i++){
		cin >> arr[i]; 
	}

	int ans = helper(arr ,n);
	cout << ans << endl; 
	return 0; 
}