/*
1839A
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int ans = (n-1)/k;
        ans++;
        if((n-1) % k) ans++;
        cout << ans << "\n";
    }
    return 0;
}