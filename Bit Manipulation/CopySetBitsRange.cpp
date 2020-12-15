#include<iostream>
using namespace std ; 

int helper(int a , int b , int l , int r){
	int mask1 = (1 << (r-l+1)); 
	mask1--;
	mask1 = (mask1 << (l-1)); 

	int mask2 = mask1 & a ;
	return (mask2|b);
}

int main(){
	int a , b , l , r ; 
	cin >> a >> b >> l >> r; 
	int ans = helper(a,b,l,r); 
	cout << ans << endl; 
	return 0; 
}