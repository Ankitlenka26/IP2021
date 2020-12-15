#include<bits/stdc++.h> 
using namespace std ; 

int main(){
	int n ; 
	cin >> n ; 
	int val =0 ;
	int temp ;
	for( int i= 0 ; i<n ; i++){ 
		cin >> temp ;
		val = (val^ 2*temp);
	}

	cout << val << endl; 
	return 0; 
}