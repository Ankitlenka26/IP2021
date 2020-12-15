#include<iostream>
using namespace std ;

int largestPower(int n){
	int x=0; 
	while((1<<x) <= n){
		x++;
	}

	return x-1;
}

int helper(int n){

	if(n==0){
		return 0; 
	}if(n==1){
		return 1; 
	}
	int x = largestPower(n);

	int prevSet = (1<<(x-1))*x ; 
	int msbOnes = n - (1<<x) +1; 
	int smallAns = helper(n-(1<<x)); 
	return prevSet + msbOnes + smallAns; 
}

int main(){
	int n ; 
	cin >> n ; 
	int count = helper(n); 
	cout << count <<endl;
	return 0; 
}