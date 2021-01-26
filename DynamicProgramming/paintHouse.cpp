#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long int
using namespace std; 
ll helper(vector<ll>& r , vector<ll>& b , vector<ll>& g , int n){
	if(n==0) return 0; 
	int red = r[0]; 
	int blue = b[0]; 
	int green = g[0]; 

	for(int i=1 ; i<n ; i++){
		// if we choose red for the current house 
		int nred = r[i] + min(blue,green);
		int nblue = b[i] + min(red,green); 
		int ngreen = g[i] + min(blue,red); 
		red = nred ; 
		blue = nblue ; 
		green = ngreen;  
	}

	return min(red , min(blue , green)); 
}
int main(){
	int n;
	cin >> n ; 
	vector<ll> r(n) , b(n) , g(n); 
	for(int i=0 ;i<n ;i++){
		cin >> r[i] >> b[i] >> g[i]; 
	}
	ll ans = helper(r,b,g,n); 
	cout << ans << endl; 
	return 0; 
}