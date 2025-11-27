/*
1175A
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        long long n, k; cin >> n >> k; 
        long long ans = 0; 
        while(n){
            ans += n % k; 
            n -= (n % k); 
            if(n==0) break; 
            ans++; 
            n /= k; 
        }
        cout << ans << "\n"; 
    }

    return 0; 
}