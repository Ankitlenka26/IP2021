#include<iostream>
#include<vector>
#include<string>
using namespace std; 

int main(){
	int n ; 
	cin >> n ; 
	int *arr = new int[n];
	int xxory = 0; 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
		xxory ^= arr[i];
	}

	int rmsb = xxory & (-xxory); 
	int x =0 , y=0 ;
	for(int i=0 ;i<n ;i++){
		if((arr[i] & rmsb) == 0){
			x ^= arr[i]; 
		}else{
			y ^= arr[i]; 
		}
	}

	if(x < y){
		cout << x << endl; 
		cout << y << endl;
	}else{
		cout << y << endl ;
		cout << x << endl ;
	}
	return 0; 
}