/*
1174E
*/
    
#include <iostream>
#include <vector>
    
using namespace std; 
    
const long long MOD = 1e9+7; 
// vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxI+1, vector<int>(maxJ+1, 0)));
int dp[1000001][21][2] = {}; 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    long long n; cin >> n; 
    
    int maxI = 0, maxJ = 0;
    for(int i = 0; i < 20; ++i){
        if((1 << i) <= n) maxI = i; 
    }
    
    if((1 << (maxI - 1)) * 3 <= n) maxJ = 1; 
    // 1e6 * 20 * 2, why is too big? 
    
    dp[0][maxI][0] = 1; 
    if(maxJ) dp[0][maxI-1][maxJ] = 1; 
    for(int idx = 0; idx < n-1; ++idx){
        for(int i = 0; i <= maxI; ++i){
            for(int j = 0; j <= maxJ; ++j){
                long long num = (1 << i) * (2*j + 1); 
                dp[idx+1][i][j] += 1LL * dp[idx][i][j] * (n/num - idx-1) % MOD;
                dp[idx+1][i][j] %= MOD; 
                if(i){
                    dp[idx+1][i-1][j] += 1LL *dp[idx][i][j] * (n/(num/2) - n/num) % MOD; 
                    dp[idx+1][i-1][j] %= MOD; 
                }
                if(j){
                    dp[idx+1][i][j-1] += 1LL * dp[idx][i][j] * (n/(num/3) - n/num)% MOD;  
                    dp[idx+1][i][j-1] %= MOD; 
                }
    
            }
        }
    }
    cout << dp[n-1][0][0] << "\n";
    return 0;
}