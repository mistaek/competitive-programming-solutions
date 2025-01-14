/*
2055A
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, a, b; cin >> n >> a >> b; 
        if(abs(a - b) % 2) cout << "NO\n"; 
        else cout << "YES\n"; 
    }

    return 0;
}