/*
992C
*/

#include <iostream>

using namespace std; 

long long MOD = 1e9+ 7;

long long binexp(long long b, long long exp){
    long long ans = 1, pow = b; 
    for(int i = 0; i < 60; ++i){
        if(exp & (1LL << i)){
            ans *= pow; 
            ans %= MOD; 
        }
        pow *= pow; 
        pow %= MOD; 
    }
    return ans; 
}
int main(){
    long long x, k; 
    cin >> x >> k;
    if(x == 0){
        cout << 0 << "\n"; 
        return 0;
    }
    x %= MOD; 
    
    long long num = (2LL * x) % MOD; 
    if(k){
        num = binexp(2, k+1) * x; 
        num %= MOD; 
        num -= binexp(2, k);
        num += 1; 
        num %= MOD; 
        if(num < 0) num += MOD;  
    }
    cout << num << "\n";
    return 0;
}