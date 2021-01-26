#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 
    int helper(vector<int>& arr) {
        if(arr.size()==0) return 0; 
        int obsp = -arr[0]; 
        int ossp = 0; 
        int ocsp = 0; 
        
        for(int i=1 ;i<arr.size() ;i++){
            int nbsp = 0; 
            int nssp =0 ; 
            int ncsp = 0; 
            
            nbsp = max(obsp , ocsp-arr[i]); 
            nssp = max(obsp + arr[i] , ossp); 
            ncsp = max(ocsp,ossp); 
            
            obsp = nbsp ;
            ossp = nssp ; 
            ocsp = ncsp;
        }
        
        return ossp;
    }
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}
	int ans = helper(arr); 
	cout << ans << endl; 
	return 0; 
}