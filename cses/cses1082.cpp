/*
cses 1082
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

int main(){
    long long n; cin >> n; 
    
    long long ans = n; 

    long long MOD = 1e9+7; 
    ans %= MOD; 
    long long prev = n;
    long long i = 2; 
    for(; i * i <= n; ++i){
        ans += i * (n/i); // contribution from i 
        ans %= MOD; 
        long long nxt = n/i, delta = prev - nxt; 
        //cout << "FROM " << nxt+1 << " to " << prev << ", DIVISOR IS " << i-1 << "\n";
        //cout << "GIVES US " << (i-1) * (delta * (delta+1) /2) + delta * nxt << "\n";
        // need to sum numbers from nxt + 1 to prev and multiply by i
        long long sum = (delta % MOD) * ((delta+ 1) % MOD)/2;
        sum%= MOD; 
        sum += (delta % MOD) * (nxt % MOD); 
        sum %= MOD; 
        sum *= (i-1); 
        sum %= MOD; 
        ans += sum;  
        prev = nxt; 
    }
    //cout << ans << "\n";
    if((i-1) * (i-1) != n){
        long long nxt = i-1, delta = prev - nxt; 
        //cout << "FROM " << nxt+1 << " to " << prev << ", DIVISOR IS " << i-1 << "\n";
        //cout << "GIVES US " << (i-1) * ((delta * (delta+1) /2) + delta * nxt) << "\n";
        // need to sum numbers from nxt + 1 to prev and multiply by i
        long long sum = (delta % MOD) * ((delta+ 1) % MOD)/2;
        sum%= MOD; 
        sum += (delta % MOD) * (nxt % MOD); 
        sum %= MOD; 
        sum *= (i-1); 
        sum %= MOD; 
        ans += sum;  
        ans %= MOD; 
    }

    cout << ans << "\n";
    return 0;
}