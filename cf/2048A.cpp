/*
2048A
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int x; cin >> x; 
        if(x % 33) cout << "NO\n"; 
        else cout << "YES\n";
    }
    return 0;
}