#include<iostream>
#include<string>
using namespace std; 

bool isDivisible(string s){
	int even = 0 , odd= 0; 
	for(int i=0 ;i<s.size() ; i++){
		if(i%2==0){
		   even += s[i] - '0';
		}else{
			odd += s[i] - '0';
		}
	}

	return (abs(even-odd)%11) == 0 ;
}
int main(){

	string s ; 
	cin >> s ; 
	bool ans = isDivisible(s); 
	if(ans){
		cout << "true" << endl; 
	}else{
		cout << "false" << endl; 
	}

	return 0; 
}