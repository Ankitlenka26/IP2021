#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std; 

vector<string> helper(int n){
    // Base Cases 
    if(n == 0){
       vector<string> bres ; 
       bres.push_back("");
       return bres; 
    }else if(n<0){
        vector<string> bres; 
        return bres; 
    }else{
        
        // Recursion and calculation 
        vector<string> path1 = helper(n-1);
        vector<string> path2 = helper(n-2);
        vector<string> path3 = helper(n-3);
        vector<string> path; 
        for(int i=0 ;i<path1.size() ; i++){
            path.push_back("1" + path1[i]); 
        }
        for(int i=0 ;i<path2.size() ; i++){
            path.push_back("2" + path2[i]); 
        }
        for(int i=0 ;i<path3.size() ; i++){
            path.push_back("3" + path3[i]); 
        }
        
        // return
        
        return path;
        
    }
}

int main(){
    int n ; 
    cin >> n ; 
    vector<string> ans = helper(n);
    int cnt = 0;
    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}