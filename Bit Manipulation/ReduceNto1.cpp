#include<bits/stdc++.h> 
using namespace std ; 
int minNumOfSteps(long n){
	int res = 0; 
	if(n < 1){
	    return 0; 
	}
	while(n!=1){
		if((n&1) == 0){
			n = n/2; 
		}else if(n==3){
			n = n-1;
		}else if((n&3) ==1){
			n = n-1; 
		}else if((n&3) == 3){
			n = n+1;
		}
		res++; 
	}

	return res;
}
int main(){
	int n ; 
	cin >> n ; 
	int ans = minNumOfSteps(n); 
	cout << ans << endl; 
	return 0; 
}