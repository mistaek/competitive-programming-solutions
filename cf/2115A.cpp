/*
2115A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int target = 0;
        vector<int> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            if(i) target = gcd(target, a[i]); 
            else target = a[i]; 
        }

        vector<vector<int>> dp(2, vector<int>(5001, -1)); 
        // using first i elements, smallest set to reach gcd j
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= 5000; ++j){
                dp[1][j] = dp[0][j];
                if(j == a[i]) dp[1][j] = 1; 
                if(dp[0][j] != -1){
                    if(dp[1][gcd(j, a[i])] == -1) dp[1][gcd(j, a[i])] = 1 + dp[0][j]; 
                    else dp[1][gcd(j, a[i])] = min(dp[1][gcd(j, a[i])], 1 + dp[0][j]);
                    //cout << gcd(j, a[i]) << " reachable with " << dp[1][gcd(j, a[i])] << "\n";
                }
            }
            dp[0] = dp[1];
        }

        int ops = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] != target) ++ops; 
        }
        //cout << target << " " << ops << "\n";
        if(dp[0][target] != 1) ops += dp[0][target] - 2; 
        cout << ops << "\n";
    }
    return 0;
}