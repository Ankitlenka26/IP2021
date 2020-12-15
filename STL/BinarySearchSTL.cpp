#include<bits/stdc++.h> 
using namespace std ; 

int main(){
	int arr[] = {20 , 30 , 40 , 40, 40 , 50 , 100 , 1100}; 
	int n = sizeof(arr)/sizeof(int); 

	// Search in a sorted array  (If the element is present or not )

	int key ; 
	cin >> key ; 

	bool present = binary_search(arr , arr+n , key); 

	if(present){
		cout << "present" << endl;
	}else{
		cout << "not present" << endl ;
	}

	// Two more things 

	// Get the index of the element 
	// lower_bound(s,e,key) and upper_bound(s,e,key)
	// they return the address where the element is stored 


	// it will give the first element addres where element >= key 
	auto it1 = lower_bound(arr , arr+n , key); 
	int index1 = it1 - arr ; 
	// it will give the first element address where element > key
	auto it2 = upper_bound(arr , arr+n , key); 
	int index2 = it2 - arr ; 

	cout << index1 << " " << index2 << endl ;

	cout << "occurence freq of key " << index2 - index1 << endl; 

	return 0; 
}