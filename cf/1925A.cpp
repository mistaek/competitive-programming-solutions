/*
1925A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        for(int i = 0; i < n * k; i++){
            cout << (char)('a' + (i % k)); 
        }
        cout << "\n";
    }
    return 0;
}