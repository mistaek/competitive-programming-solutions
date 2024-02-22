/*
w24e
*/

#include <iostream>
#include <cmath>

using namespace std; 

int main(){
    long long d, r; cin >> d >> r; 
    long long dp[d+1][2501] = {};
    long long sdp[d+1][2501] = {};
    for(int i = 0; i <= r*r; i++){
        sdp[d][i] = 0;
        dp[d][i] = 1;
    }


    long long MOD = 1e9+7;
    for(long long i = d-1; i >=0; i--){ 
        for(long long j = 0; j <= r*r; j++){
            for(long long k= 0; k * k <= j; k++){
                if(k){
                    sdp[i][j] += k * 2LL * (dp[i+1][j - (k * k)]);
                    sdp[i][j] %= MOD;
                    sdp[i][j] += (2LL* sdp[i+1][j-k*k]);
                    sdp[i][j] %= MOD;
                    dp[i][j] += 2LL * dp[i+1][j - (k * k)];
                    dp[i][j] %= MOD;
                }
                else{
                    sdp[i][j] += sdp[i+1][j-k*k];
                    sdp[i][j] %= MOD;
                    dp[i][j] += dp[i+1][j - (k*k)]; 
                    dp[i][j] %= MOD;
                }
            }
            //cout << i << " " << j << " " << sdp[i][j] << " " << dp[i][j] << "\n";
        }
    }
   
    cout << sdp[0][r*r] << "\n";
    return 0;
}