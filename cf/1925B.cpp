/*
1925B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


int main(){
    int t; cin >> t; 
    while(t--){
        long long x, n; cin >> x >> n;
        long long ans = 0;
        for(long long i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(x/ i >= n) ans = max(ans, i);
                if(i >= n) ans = max(ans, x/i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}