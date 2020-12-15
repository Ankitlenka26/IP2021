#include<bits/stdc++.h> 
using namespace std ; 

void oneMissingOneRepeating(int* arr , int n){
	int Xor =0 ;


	for(int i=0 ;i<n ; i++){
		Xor ^= arr[i]; 
	}

	for(int i=1; i<= n ;i++){
		Xor ^= i ; 
	}

	int rsb = Xor & -Xor; 

	int x =0 , y=0 ; 

	for(int val :arr){
		if(val & rsb == 0){
			x ^= arr[i]; 
		}else{
			y ^= arr[i]; 
		}
	}

	for(int i=1 ; i<=n ;i++){
		if(i & rsb == 0){
			x ^= i ; 
		}else{
			y ^= i ; 
		}
	}

	for(int val :arr){
		if(val == x){
			cout << "Missing Number ->" << y << endl ; 
			cout << "Repeating Number ->" << x << endl ;
			break;
		}if(val==y){
			cout << "Missing Number ->" << x << endl ; 
			cout << "Repeating Number ->" << y << endl ;
			break;
		}
	}

	return ;
}

int main(){
	int n ; 
	cin >> n ; 
	int * arr = new int[n]; 
	for(int i=0 ; i<n ;i++){
		cin >> arr[i]; 
	}

	oneMissingOneRepeating(arr , n); 
	return 0; 
}