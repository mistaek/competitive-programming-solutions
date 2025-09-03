/*
2133D
*/
#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        long long h[n], dp[n]; 
        for(int i = 0; i < n; ++i){
            cin >> h[i]; 
        }
        dp[0] = h[0]; 
        dp[1] = h[0] + h[1] - 1; 
        for(long long i = 2; i < n; ++i){
            dp[i] = min(dp[i-1] + h[i] - 1, dp[i-2] + h[i-1] + h[i] - min(i, h[i])); 
            //cout << i << " " << dp[i-1] + h[i] - 1 << " " << dp[i-2] + h[i-1] + h[i] - min(i, h[i]) << "\n";
        }
        cout << dp[n-1] << "\n"; 
    }
    return 0;
}