
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ; 
vector<int> sol ; 
void solution(int* people , int nskills , int cp , vector<int> oneSolution , int smask){
    if(cp == nskills){
        if(smask == ((1<<nskills)-1)){
            if(sol.size()==0 || sol.size() > oneSolution.size()){
                sol = oneSolution; 
            }
        }
        
        return ; 
    }
    
    solution(people , nskills , cp+1 , oneSolution , smask); 
    oneSolution.push_back(cp);
    solution(people , nskills , cp+1 , oneSolution , (smask | people[cp])); 
    oneSolution.pop_back(); 
    
    return ; 
}
int main(){
    int n ; cin >> n ; 
    unordered_map<string , int> smap; 
    for(int i=0 ;i<n ; i++){
        string temp ; 
        cin >> temp ; 
        smap[temp] = i; 
    }
    
    int np ; 
    cin >> np ; 
    int* people = new int[np]; 
    for(int i=0 ;i<np ;i++){
        int personSkills ; 
        cin >> personSkills ; 
        people[i] =0 ;
    	for (int j = 0; j < personSkills; j++) {
    		    string skill; 
    		    cin >> skill; 
    			int snum = smap[skill];
    			people[i] = people[i] | (1 << snum);
    	}
    }
    vector<int> oneSolution ; 
    solution(people, n, 0,oneSolution, 0);
    cout << "[";
    for(int i=0 ;i<sol.size(); i++){
        if(i == sol.size()-1){
            cout << sol[i] << "]";
        }else{
            cout << sol[i] << ", " ;
        }
    }
    return 0; 
}