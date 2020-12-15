#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std ; 

void helper(vector<int>& arr , int n){
	sort(arr.begin() , arr.end()); 
	vector<string>* res = new vector<string>(); 
	int min = INT_MAX; 

	for(int i=0 ; i<arr.size()-1; i++){
		int Xor = arr[i]^arr[i+1]; 
		if(Xor < min){
			min = Xor;
			res = new vector<string>();  
			res.push_back(to_string(arr[i]) + " " + to_string(arr[i+1])); 
		}else if(Xor == min){
			res.push_back(to_string(arr[i]) + " " + to_string(arr[i+1]));
		}
	}

	for(string val : res){
		cout << val << endl ;
	}

	return ;
}

int main(){
	int n ; 
	cin >> n ; 
	vector<int> v(n,0); 
	for(int i=0 ; i<n ;i++){
		cin >> v[i]; 
	}

	helper(arr, n); 
	return 0; 
}