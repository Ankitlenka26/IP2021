#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int 
using namespace std ; 

int main(){
	int n , k ; 
	cin >> n >> k ; 

	ll same = k*1; 
	ll diff = k*(k-1); 
	ll total = same + diff; 

	for(int i=3 ; i<= n ;i++){
		same = diff; 
		diff = total*(k-1); 
		total = same + diff; 
	}

	cout << total << endl; 
	return 0; 
}