#include<bits/stdc++.h> 
using namespace std ; 

char maxFreq(string s){
	unordered_map<char , int> m ; 
	for(int i=0 ;i<s.size();i++){
		m[s[i]]++; 
	}
	char ch; 
	int max = INT_MIN;  
	for(auto it: m){
		if(it.second > max){
			max = it.second ;
			ch = it.first;
		}
	}

	return ch; 
}

int main(){
	string s ; 
	cin >> s ; 
	char ans = maxFreq(s); 
	cout << ans <<endl;
	return 0; 
}