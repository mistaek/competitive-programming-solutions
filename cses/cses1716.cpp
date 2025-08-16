/*
cses 1715
*/

#include <iostream>
#include <string> 

using namespace std; 

long long MOD = 1e9+7; 
long long binexp(long long a, long long e){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 32; ++i){
        if(e & (1LL << i)) ans = ans * pow % MOD; 
        pow = pow * pow % MOD;  
    }
    return ans; 
}

long long fac[2000001], invfac[2000001] = {}; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    fac[0] = 1; 
    for(int i = 1; i < 2000001; ++i){
        fac[i] = i * fac[i-1] % MOD; 
    }
    invfac[2000000] = binexp(fac[2000000], MOD -2); 
    for(int i = 2e6 - 1; i >= 1; --i) invfac[i] = (i+1) * invfac[i+1] % MOD ;
    invfac[0] = 1; 
    
    int n, m; cin >> n >> m; 
    cout << (fac[n+m-1] * invfac[m] % MOD) * invfac[n-1] % MOD  << "\n"; 
    return 0;
}