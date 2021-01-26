#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long int
using namespace std; 

int countEncodings(string s){
	int n = s.size(); 
	vector<int> dp(n,0); 
	dp[0] = 1; 
	for(int i=1; i<n ;i++){
		if(s[i] == '0' && s[i-1] =='0'){
			dp[i] = 0 ;
		}else if(s[i] != '0' && s[i-1] == '0'){
			dp[i] = dp[i-1]; 
		}else if(s[i] == '0' && s[i-1] != '0'){
			if(s[i-1] == '1' || s[i-1] == '2'){
				dp[i] = ((i-2) >= 0 ? dp[i-2] : 1); 
			}else{
				dp[i] =0 ;
			}
		}else{
		    int rem = stoi(s.substr(i-1,2)); 
		  //  cout << rem << endl ;
			if(rem <= 26){
				dp[i] = dp[i-1] + ((i-2) >= 0 ? dp[i-2] : 1);
			}else{
				dp[i] = dp[i-1]; 
			}
		}
	}
	
// 	for(int val : dp){
// 	    cout << val << endl; 
// 	}
	return dp[n-1]; 
}
int main(){
	string s ; 
	cin >> s; 
	int ans = countEncodings(s); 
	cout << ans << endl; 
	return 0; 
}