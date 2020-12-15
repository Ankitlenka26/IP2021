#include<iostream>
#include<vector> 
using namespace std;

long bitDiffCount(vector<int>& arr){
	long res =0;
	for(int i=0 ;i<32 ; i++){
		long counton = 0; 
		for(int val :arr){
			if((val&(1<<i)) !=0){
				counton++;
			}
		}

		long countOff = arr.size() - counton; 
		long diff = counton*countOff*2; 
		res += diff; 
	}
	return res; 
} 

int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n,0);
	for(int i=0 ;i<n ; i++){
		cin >> arr[i]; 
	}

	long count = bitDiffCount(arr); 
	cout << count << endl; 
	return 0; 
}