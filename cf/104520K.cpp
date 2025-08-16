/*
104520K
*/

#include <iostream>

using namespace std; 

long long MOD = 998244353; 

long long fac[100001], invfac[100001];

long long binexp(long long a, long long e){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 32; ++i){
        if(e & (1LL << i)) ans = ans * pow % MOD; 
        pow = pow * pow % MOD; 
    }
    return ans; 
}
int main(){
    fac[0] = 1; 
    for(long long i = 1; i < 100001; ++i){ fac[i] = i * fac[i-1] % MOD;}
    invfac[100000] = binexp(fac[100000], MOD-2); 
    for(long long i = 99999; i >= 0; -- i) invfac[i] = (i+1) * invfac[i+1] % MOD; 

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        for(long long int i = 1; i <= n; ++i){
            if(i > 1) cout << " "; 
            if(i == 1 || 2*(i-1) >= n){
                cout << 0; 
                continue; 
            }
            long long ans; 
            //first: generate sequences: (n - i - 1) choose (i-2)
            ans = fac[n-i-1]  * invfac[i-2] % MOD; 
            ans = ans * invfac[n - i - i + 1] % MOD;
            
            // second: permute sequence
            ans = ans * fac[2 * (i-1)] % MOD; 
            // last: place
            ans = ans * fac[(n - 2*(i-1)) + 1] % MOD;
            cout << ans; 
        }
        cout << "\n";
    }    

    return 0;
}