/*
2170A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        if(n == 1) cout << 1 << "\n"; 
        else if(n == 2) cout << 9 << "\n"; 
        else if(n == 3) cout << 29 << "\n";
        else if (n == 4) cout << 56 << "\n"; 
        else {
            cout << 5 *(n * n - n - 1) << "\n";
        }
    }
    return 0;
}