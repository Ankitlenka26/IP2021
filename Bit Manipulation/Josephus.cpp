#include<iostream>
#include<math.h>
using namespace std ; 

int powerOf2(int n){
    int i=1;
    while( 2*i <= n){
        i = i*2;
    }
    
    return i;
}

int main(){
    int n ; 
    cin >> n ; 
    int i = powerOf2(n);
    int l = n - i;
    cout << 2*l +1 << endl;
    return 0;
}