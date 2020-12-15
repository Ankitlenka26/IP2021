#include<bits/stdc++.h> 
using namespace std ; 

/*
Given an integer, check whether it is Bleak or not.
A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number 
x and set bit count in x, i.e., x + countSetBits(x) is 
not equal to n for any non-negative number x.
*/

// This can be easily done in o(nlogn) -> logn for bit count and o(n) for traversing the entire bit range 

int isBleak(int n){
	for(int i= n - (int)(log(n)/log(2)) ; i<n ; i++){
		int temp = i + __builtin_popcount(i); 
		if(temp == n){
			return false;
		}
	} 

	return true;
}

int main(){
	int n; 
	cin >> n ; 
	int ans = isBleak(n); 
	cout << ans << endl; 
	return 0; 
}