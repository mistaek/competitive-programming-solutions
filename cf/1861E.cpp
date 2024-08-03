/*
1861E
AC :)
*/

#include <iostream>

using namespace std; 

long long MOD = 998244353;

long long binexp(long long a, long long b){
    long long pow = a, ans = 1; 
    for(int i = 0; i < 30; i++){
        if(b & (1LL << i)) ans *= pow; 
        pow *= pow; 
        pow %= MOD; 
        ans %= MOD; 
    }

    return ans; 
}

long long dp1[4002][4002] = {};
int main(){
    int n, k; cin >> n >> k; 
    dp1[0][k] = 1; 
    long long psum[k+1] = {}; 

    for(int i = 0; i <= n; i++){
        //cout << dp1[i][0] << "\n";
        for(int j = 1; j <= k; j++){
            if(i){
                psum[j] = dp1[i-1][j] + psum[j-1];
                psum[j] %= MOD;
            }
            if(j < k){
                dp1[i][j] += psum[j];
                dp1[i][j] %= MOD;
            }
            dp1[i+1][j-1] += j * dp1[i][j]; 
            dp1[i+1][j-1] %= MOD; 
            //cout << i << " " << j << " " << dp1[i][j] << "\n"; 
        }     
    }
    long long ans[n+1] = {};
    long long inv = binexp(k, MOD-2);
    long long tot = 1;
    for(int i = 1; i <= n; i++){
        tot *= k; tot %= MOD;
        long long cpy = tot; 
        if(i >= k) cpy *= binexp(inv, k-1);
        cpy %= MOD;
        for(int j = k; j <= i; j++){
            cpy *= inv; cpy %= MOD; 
            ans[i]+= dp1[j][0]*cpy;
            //if(i == 3) cout << cpy << " " << dp1[j][0] << "\n";
            ans[i] %= MOD;
            ans[i] += dp1[j][0] * ans[i-j];
            ans[i] %= MOD;
        }
        //cout << i << " " << ans[i] << "\n";
    }
    cout << ans[n] << "\n";

    return 0;
}