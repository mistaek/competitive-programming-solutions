/*
1155B
*/
    
#include <iostream>
#include <vector>
#include <set>
    
using namespace std; 
    
int main(){
    int n; cin >> n; 
    
    int rem = (n-11)/2; // both players remove this amount
    vector<int> eights; 
    vector<int> others; 
    for(int i = 0; i < n; ++i){
        char c; cin >> c; 
        if(c - '0' == 8) eights.push_back(i); 
        else others.push_back(i); 
    }
    
    if(eights.size() <= rem){
        cout << "NO\n"; 
    }
    else if(others.size() <= rem){
        cout << "YES\n"; 
    }
    else cout << ((eights[rem] < others[rem]) ? "YES\n" : "NO\n"); 
    return 0;
}