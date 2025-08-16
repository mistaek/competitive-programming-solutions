/*
1606E
*/

#include <iostream>

using namespace std; 

long long MOD = 998244353; 

long long dp[501][501]; 

long long binexp(long long a, long long e){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 32; ++i){
        if(e & (1LL << i)) ans = ans * pow % MOD; 
        pow = pow * pow % MOD; 
    }
    return ans; 
}
long long fac[501], invfac[501]; 
long long nck[501][501];
long long ex[501][501];
int main(){
    for(int i = 1; i < 501; ++i){
        for(int j = 0; j < 501; ++j){
            ex[i][j] = binexp(i, j); 
        }
    }
    fac[0] = 1; 
    for(int i = 1; i < 501; ++i) fac[i] = fac[i-1] * i %MOD; 
    invfac[500] = binexp(fac[500], MOD-2);
    for(int i = 499; i >= 0; --i) invfac[i] = invfac[i+1] * (i+1) % MOD; 

    for(int i = 0; i < 501; ++i){
        for(int j = 0; j <= i; ++j){
            nck[i][j] = fac[i] * invfac[j] % MOD; 
            nck[i][j] = nck[i][j] *invfac[i-j] % MOD; 
        }
    }

    dp[1][1] = 0;
    dp[1][0] = 1;  
    for(int i = 2; i <= 500; ++i) dp[1][i] = 1; 

    for(int i = 2; i <= 500; ++i){
        dp[i][0] = 1; 
        dp[i][1] = 0;
        for(int j = 2; j <= 500; ++j){
            if(j - 1 >= i){
                // all must die
                dp[i][j] = ex[i][j]; 
                continue; 
            }
            for(int k = 0; k <= j; ++k){
                //cout << i << " is MAXHP, " << j << " alive, try to kill " << k << "\n"; 
                // i is max hp, j is num alive
                // everyone takes j-1 damage next round
                // we are choosing how many to kill this round (k)
                // jck sets to kill                
                long long local = nck[j][k];
                local = local * ex[j-1][k] % MOD; // hps can be 1 ... j-1 
                local = local * dp[i - (j-1)][j-k] % MOD; // next maxhp is i - (j-1)
                
                dp[i][j] += local; 
                //cout << local << " ways" << "\n";
                dp[i][j] %= MOD; 
            }
        }
    }

    int n, x; cin >> n >> x; 
    cout << dp[x][n] << "\n";


    //brain off just compute everything

    return 0;
}

