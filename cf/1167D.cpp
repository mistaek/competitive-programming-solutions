/*
1167D
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    string s; 
    int n; cin >> n >> s; 
    
    int depth = 0, maxdepth = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '(') ++depth; 
        else --depth; 
        maxdepth = max(maxdepth, depth);
    }
    int sep = maxdepth/2; 
    depth = 0;
    //cout << maxdepth << " " << sep << "\n";
    for(int i = 0; i < n; ++i){
        if(s[i] == '(') ++depth; 
        if(depth <= sep) cout << 0;
        else cout << 1; 
        if(s[i] == ')') --depth; 
    }
    cout << "\n"; 
    return 0;
}