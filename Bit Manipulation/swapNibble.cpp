#include<bits/stdc++.h> 
using namespace std ; 

    int swapNibbles(unsigned char x){
        // code here
        unsigned char lowerNibble = 15; 
        unsigned char higherNibble = 15 << 4; 
        
        unsigned char num1 = ((x&lowerNibble)<<4); 
        unsigned char num2 = ((x&higherNibble)>>4);
        
        return num1|num2; 
    }

int main(){
	unsigned char x ; 
	cin >> x ;
	cout << swapNibbles(x) << endl;
	return 0; 
}