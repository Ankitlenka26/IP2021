#include<iostream>
using namespace std ; 

// Algorithm to find the number of set bits in a number 
int main(){
    int x ; 
    cin >> x ; 
    int count =0 ;
    int rsbm =0 ;
    while(x){
        count++; 
        rsbm = x & (-x); 
        x = x-rsbm;
    }
    cout << count << endl; 
    return 0 ;
}