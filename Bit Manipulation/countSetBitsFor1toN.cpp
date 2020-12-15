#include<bits/stdc++.h> 
using namespace std ; 

    vector<int> countBits(int num) {
        vector<int> v(num+1, 0); 
        for(int i=1; i<= num ; i++){
            if(i%2==1){
                v[i] = v[i-1] +1 ;
            }else{
                v[i] = v[i/2]; 
            }
        }
        
        return v ; 
    }

int main(){
	int num ; 
	cin >> num ;
	vector<int> ans = countBits(num); 
	for(int val : ans){
		cout << val << " "; 
	}
	cout << endl ;
	return 0; 
}