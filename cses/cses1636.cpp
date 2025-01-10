/*
cses1636
AC
using long long makes problem TLE,cses is 32bit?
*/

#include <iostream>

using namespace std; 

int MOD =1e9+7;


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x; 
    int coins[n]; 
    for(int i = 0; i < n; ++i) cin >> coins[i]; 

    int dp[x+1] = {};
    dp[0] = 1; 
    for(int i = 0; i < n; ++i){
        for(int j = coins[i]; j <= x; ++j){
            dp[j] += dp[j-coins[i]]; 
            dp[j] %= MOD; 
        }
    }
    cout << dp[x] << "\n";
    return 0;
}