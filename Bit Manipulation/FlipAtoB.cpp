#include<iostream>
using namespace std ; 

int flip(int a , int b){
    int val = a^b ; 
    int res =0 ; 
    while(val > 0){
        int rsb = (val & -val); 
        res++;
        val -= rsb;
    }
    
    return res;
}

int main(){
    int a , b ; 
    cin >> a >> b ; 
    
    int count = flip(a,b); 
    cout << count << endl; 
    
    return 0; 
}