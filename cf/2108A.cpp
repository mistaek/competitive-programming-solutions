/*
2108A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long ans = 0;
        for(int i = 0; i < n/2; ++i){
            
            ans += n - 2*i - 1; 
        }
        ans += 1; 
        cout << ans << "\n"; 
    }
    return 0;
}