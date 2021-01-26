#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long int
using namespace std; 

ll arrangeHouses(ll n){
	if(n==0){
		return 0; 
	}

	ll oldS = 1; 
	ll oldB = 1; 
	for(ll i=2 ; i<= n ;i++){
		ll newB = oldS; 
		ll newS = oldS + oldB; 
		oldB = newB ;
		oldS = newS; 
	}

	return oldB + oldS; 
}
int main(){
	ll n ; 
	cin >> n ; 
	ll ans = arrangeHouses(n); 
	// since the number of ways we can arrange one side is equal to the number of ways we can arrange the other side 
	// therefore the total number of arrangements will be ans*ans 
	cout << ans*ans << endl ;
	return 0; 
}