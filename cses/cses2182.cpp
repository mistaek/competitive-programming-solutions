/*
cses2182
*/

#include <iostream>

using namespace std; 

const long long MOD = 1e9+ 7;

long long binexp(long long a, long long e, long long mod){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 64; ++i){
        if(e & (1LL << i)) ans = ans * pow % mod; 
        pow = pow * pow % mod; 
    }
    return ans; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    long long cnt = 1, cnt2 = 1, sum = 1, product = 1; 
    
    int n; cin >> n; 

    for(int i = 0; i < n; ++i){
        long long x, k; cin >> x >> k;  
        // sum: (1-r^n)/(1-r) 
        long long xkmin1 = (binexp(x, k+1, MOD) - 1) % MOD, xmin1 = (x-1)% MOD; 
        long long termsum = xkmin1 * binexp(xmin1, MOD-2, MOD) % MOD; 
        sum = termsum * sum % MOD; 
        long long exp = (k * (k+1)/2 ) % (MOD-1); // 1 * x * x^2 * x^3 ... = x^(0 + 1 + 2 + .. k)
        product = binexp(product, (k+1), MOD); 
        product = product * binexp(x, exp * cnt2 % (MOD - 1), MOD) % MOD; 
        cnt = cnt * (k+1) % MOD;
        cnt2 = cnt2 * (k+1) % (MOD - 1);
    }
    cout << cnt << " " << sum << " " << product << "\n";
    return 0;
}