#include<iostream>
using namespace std ; 

int getRev(int n){
	int rev =0 ; 
	while(n!=0){
		int lb = (n&1); 
		rev |= lb ; 
		rev <<=1; 
		n >>=1;
	}

	rev >>=1; 
	return rev;
}
int NthPalindrome(int n){
	int count =1 ; 
	int len =1; 

	while(count < n){
		len++; 
		int elementsForThisLen = (1<<((len-1)/2));
		count += elementsForThisLen;
	}

	count -= (1<<((len-1)/2));
	int offset = n - count - 1;


	int ans (1<<len-1); 
	ans |= (offset << (len/2));

	int valFR = (ans >> (len/2)); 
	int rev = getRev(valFR); 

	ans |= rev ; 
	return ans; 
}

int main(){
	int n ; 
	cin >> n ; 
	cout << NthPalindrome(n) << endl ;
	return 0; 
}