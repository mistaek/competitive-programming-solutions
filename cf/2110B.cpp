/*
2110B
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        int bal = 0;
        bool pos = false; 
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') ++ bal; 
            else --bal; 
            if(i != s.length() - 1 && bal == 0) pos = true; 
        }
        cout << ((pos) ? "YES\n" : "NO\n"); 
    }   
    return 0;
}