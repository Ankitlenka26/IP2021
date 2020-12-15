#include<bits/stdc++.h>
#include<string>
using namespace std ;

// It makes our work with strings a lot easier 
// The string class basically wraps our char arr inside a string object 
int main(){

	// String Init 
	string s0 ; 
	string s1("hello"); 
	string s2 = "Hello world!"; 
	string s3(s2); // using copy constructor of String Class 

	if(s0.empty()){  // it returns a boolean as to whether a string is ampty or not 
		cout << "s0 is empty" << endl ;
	}
	return 0 ;
}