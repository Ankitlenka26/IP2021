#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long int
using namespace std; 
int countABC(string s){
	int x =0 ; // all subseq ending with a 
	int y = 0; // all susequence ending with b 
	int z = 0; // all subseq ending with c 

	for(int i=0 ;i<s.size() ; i++){
		if(s[i] == 'a'){
		    x = 2*x +1; 
		}else if(s[i]=='b'){
		    y = 2*y + x;
		}else if(s[i] == 'c'){
		    z = 2*z + y; 
		}
	}

	return z; 
}
int main(){
	string s ; 
	cin >> s; 
	int ans = countABC(s); 
	cout << ans << endl; 
	return 0; 
}