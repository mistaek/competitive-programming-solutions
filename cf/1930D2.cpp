/*
1930D1
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        string s; cin >> s; 
        long long ans = 0;
        long long dp[n+1] = {};
        for(int i = n-1; i >= 0; --i){
            if(s[i] == '0') dp[i] = dp[i+1]; 
            else{
                dp[i] = n-i;
                if(i + 3 < n) dp[i] += dp[i+3];
            }
            ans += dp[i];
        }
        cout << ans << "\n";
    }
    return 0;
}