#include<iostream>
using namespace std ; 
int main(){
	int n; 
	cin >> n ; 
	int mask1 = 0xAAAAAAAA; 
	int mask2 = 0x55555555;
	int x1 = (n&mask1); 
	x1 = x1>>1;
	int x2 = (n&mask2); 
	x2 = x2 << 1; 
	int ans = (x1|x2); 
	cout << ans << endl; 
	return 0 ;
}