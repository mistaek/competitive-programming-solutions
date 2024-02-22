/*
1861E
*/

#include <iostream>

using namespace std; 

long long MOD = 998244353;

int main(){
    int n, k; cin >> n >> k; 

    long long dp1[n+1][k+1] = {};

    dp1[0][k] = 1; 
    long long psum[k+1] = {}; 
    for(int i = 0; i <= n; i++){        
        for(int j = k; j > 0; j--){
            if(i > 1){
                dp1[i][j] += psum[j];
                dp1[i][j] %= MOD;
            }
            if(j < k){ 
                psum[j] = dp1[i][j]; 
                psum[j] += psum[j+1];
                psum[j] %= MOD;  
            }
            dp1[i+1][j-1] += j * dp1[i][j]; 
            dp1[i+1][j-1] %= MOD; 
        }
    }

    long long ans[n+1] = {};
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            ans[i]+= dp1[j][0];

        }
    }

    return 0;
}