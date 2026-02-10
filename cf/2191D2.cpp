/*
2191D2
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr long long MOD = 998244353;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        // number of valid prefixes 
        // length i
        // j open parentheses
        // k1: last character void vs ( vs )
        // k2: second last character void vs ( vs )
        // k3: flag for whether or not we are good
        long long dp[2][101][51][3][3][3] = {};
        
        dp[0][0][0][0][0][0] = 1;

        long long ans = 0;
        for(int idx = 0; idx < n; ++idx) {
            //cout << "\nConsidering " << s[idx] << "\n";
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j <= (n+1)/2; ++j){ 
                    for(int k1 = 0; k1 < 3; ++k1){
                        for(int k2 = 0; k2 < 3; ++k2) {
                            for(int k3 = 0; k3 < 3; ++k3) {
                                // num of sequences stays the same
                                dp[1][i][j][k1][k2][k3] += dp[0][i][j][k1][k2][k3];
                                if(s[idx] == '(') {
                                    if(k1 == 2) {
                                        dp[1][i+1][j+1][1][k1][min(2, k3 + 1)] += dp[0][i][j][k1][k2][k3];
                                    }
                                    else if(k1 == 1 && k2 == 2) {
                                        dp[1][i+1][j+1][1][k1][2] += dp[0][i][j][k1][k2][k3];
                                    }
                                    else{
                                        dp[1][i+1][j+1][1][k1][k3] += dp[0][i][j][k1][k2][k3];
                                    }
                                }
                                else {
                                    if(j == 0) continue;
                                    dp[1][i+1][j-1][2][k1][k3] += dp[0][i][j][k1][k2][k3];
                                }
                            }   
                        }
                    }
                }
            }
            for(int i = 0; i <= n; ++i) {
                for(int j = 0; j < (n+1)/2; ++j){
                    for(int k1 = 0; k1 < 3; ++k1){
                        for(int k2 = 0; k2 < 3; ++k2){
                            for(int k3 = 0; k3 < 3; ++k3){
                                dp[0][i][j][k1][k2][k3] = dp[1][i][j][k1][k2][k3] % MOD;
                                dp[1][i][j][k1][k2][k3] = 0;
                                //if(dp[0][i][j][k1][k2][k3]) cout << "Prefixes of length " << i << " with " << j << " parentheses ending with " << ((k2 == 0) ? " " : ((k2 == 1) ? "(" : ")")) <<  ((k1 == 0) ? " " : ((k1 == 1) ? "(" : ")")) << " with flag " << k3 << ": " << dp[0][i][j][k1][k2][k3] << "\n";
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i <= n; ++i){
            for(int k2 = 1; k2 < 3; ++k2) {
                ans += dp[0][i][0][2][k2][2] * max((i-2), 0);
                //if(dp[0][i][0][2][k2][2]) cout << i << ", " << k2 << ", " << dp[0][i][0][2][k2][2] << "\n";
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}