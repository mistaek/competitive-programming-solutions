/*
1279D
*/

#include <iostream>

using namespace std; 

const long long MOD = 998244353; 

long long binexp(long long a, long long e){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 32; ++i){
        if(e & (1LL << i)) ans = ans * pow % MOD; 
        pow = pow * pow % MOD;
    }
    return ans; 
}

long long inv[1000001]; 
// probability that item i is picked
long long probs[1000001] = {}, cnt[1000001] = {}; 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    for(int i = 1; i <= 1000000; ++i) inv[i] = binexp(i, MOD-2); 
    for(int i = 0; i < n; ++i){
        int k; cin >> k; 
        for(int j = 0; j < k; ++j){
            int aj; cin >> aj; 
            probs[aj] = (probs[aj] + inv[n] * inv[k]) % MOD; 
            ++cnt[aj]; 
        }
    }

    long long ans = 0;
    for(int i = 0; i < 1000001; ++i){
        long long prob = cnt[i] * inv[n] % MOD; 
        prob*= probs[i]; 
        prob %= MOD;
        ans = (ans + prob) % MOD; 
    }

    cout << ans << "\n";
    return 0;
}