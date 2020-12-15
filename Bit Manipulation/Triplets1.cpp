#include<bits/stdc++.h> 
using namespace std ; 

int noOfTriplets(vector<int>& arr , int n){
	int c =0 ; 

	for(int i=0 ;i< n ; i++){
		int val = arr[i]; 
		
		for(int k = i+1 ; k< n ;k++){
			val = (val ^ arr[k]); 

			if(val == 0){
				c += k-i ; 
			}
		}
	}

	return c ;
}

int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n,0); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i];
	}

	int ans = noOfTriplets(arr,n); 
	cout << ans << endl; 
	return 0; 
}