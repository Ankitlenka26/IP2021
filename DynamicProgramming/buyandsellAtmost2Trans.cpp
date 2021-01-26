#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std; 

int maxProfit(vector<int>& arr) {
    int overallProfit =0 ;
    int n = arr.size(); 
    vector<int> profitLeft(n) , profitRight(n); 
    int leftCurrProfit = 0;
    int leftMin = arr[0]; 
    int rightCurrProfit =0 ; 
    int rightMax= arr[n-1];
    profitLeft[0] = 0; 
    profitRight[n-1] =0 ;
    // building profit left array 
    for(int i=1; i<n ;i++){
        leftMin = min(arr[i] , leftMin); 
        leftCurrProfit = arr[i] - leftMin; 
        profitLeft[i] = max(profitLeft[i-1] , leftCurrProfit); 
    }

    // building profit right array 

    for(int i=n-2; i>= 0; i--){
        rightMax = max(rightMax , arr[i]); 
        rightCurrProfit = rightMax - arr[i]; 
        profitRight[i] = max(profitRight[i+1] , rightCurrProfit); 
    }

    for(int i=0 ;i<n ;i++){
        overallProfit = max(overallProfit , profitLeft[i] + profitRight[i]); 
    }

    return overallProfit; 
}
int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n); 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}
	int ans = maxProfit(arr); 
	cout << ans << endl; 
	return 0; 
}