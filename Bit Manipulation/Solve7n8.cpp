#include<iostream>
using namespace std ; 
int main(){
    int n ; 
    cin >> n;
    int temp = n<<3; 
    temp = temp - n ; 
    temp = temp >> 3; 
    cout << temp << endl; 
    return 0; 
}