/*
1152A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int m, n; cin >> n >> m; 

    int oddchest = 0, evenchest = 0, oddkey = 0, evenkey = 0; 
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        if(a%2) ++oddchest;
        else ++evenchest;  
    }  

    for(int i = 0; i < m; ++i){
        int a; cin >> a; 
        if(a%2) oddkey++; 
        else evenkey++; 
    }

    cout << min(evenchest, oddkey)+ min(evenkey, oddchest) << "\n";

    return 0; 
}