#include<iostream>
using namespace std ; 

int main(){
    int n , i, j, k, m ; 
    cin >> n >> i >> j >> k >> m ;
    
    cout << (n | 1<<i) << endl ;
    cout << (n & ~(1<<j)) << endl; 
    cout << (n ^ (1<<k)) << endl ;
    if(n&(1<<m)){
        cout << "true" << endl; 
    }else{
        cout << "false" << endl;
    }
    return 0; 
}