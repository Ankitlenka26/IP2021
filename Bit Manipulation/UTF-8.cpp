#include<bits/stdc++.h> 
using namespace std ; 

bool solution(vector<int> arrr , int n){
	 for(int val : arr){
	 	int remainBytes =0 ;
	 	if(!remainBytes){
		 		// checking if it is a 1 byte utf sequence 
		 	if((val >> 7) == 0b0){
		 		remainBytes =0 ;
		 	}else if((val >> 5) == 0b110){ // 1st byte  of length 2 char 
		 		remainBytes = 1;
		 	}else if((val >> 4) == 0b1110){  // 1st byte  of length 3 char 
		 		remainBytes = 2; 
		 	}else if((val >> 3) == 0b11110){  // 1st byte  of length 4 char 
		 		remainBytes = 3; 
		 	}else{
		 		return false;
		 	}
	 	}else{
	 		if((val >> 6) != 0b10){
	 			return false;
	 		}
	 		remainBytes--;
	 	}
	 }

	 return (remainBytes == 0);
}

int main(){
	int n ; 
	cin >> n ;
	vector<int> arr(n,0); 
	for(int i=0 ; i< n ;i++){
		cin >> arr[i]; 
	}
	cout << solution(arr , n) << endl; 
	return 0;
}