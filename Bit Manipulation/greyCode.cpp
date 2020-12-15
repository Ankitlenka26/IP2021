#include<iostream>
 #include<vector>
 #include<math.h>
 using namespace std;
 
 vector<int> grayCode(int n) {
     if(n < 1){
         vector<int> ans; 
         return ans; 
     }
     if(n==1){
         vector<int> ans; 
         ans.push_back(0); 
         ans.push_back(1); 
         return ans; 
     }
     
     vector<int> smallAns = grayCode(n-1); 
     vector<int> res ;
     for(int i=0 ; i<smallAns.size() ;i++){
         res.push_back(smallAns[i]); 
     }
     for(int i= smallAns.size()-1 ; i>=0 ; i--){
         res.push_back(smallAns[i] + pow(2,n-1)); 
     }
     
     return res; 
 }
     
 
 int main(){
     int n;
     cin>>n;
     vector<int> res = grayCode(n);
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
     return 0; 
 }