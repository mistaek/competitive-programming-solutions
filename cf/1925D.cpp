/*
1925D
AC
*/

#include <iostream>

using namespace std; 

long long MOD = 1e9+7;

long long binexp(long long a, long long b){
    long long pow = a; long long ans = 1;
    for(int i = 0; i < 60; i++){
        if(b & (1LL << i)){
            ans *= pow;
        }
        ans %= MOD;
        pow *= pow; 
        pow %= MOD;
    }
    return ans; 
}

long long inv(long long n){
    return binexp(n, MOD-2);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        long long n, m, k; cin >> n >> m >> k; 
        long long sum = 0; 
        for(int i = 0; i < m; i++){
            int a, b, f; 
            cin >> a >> b >> f;
            sum += f; 
        }
        sum %= MOD;
        long long ans = 0, choose = (n * (n-1))/2;
        choose %= MOD;
        for(int i = 0; i < k; i++){
            ans += (sum * inv(choose)) % MOD;
            ans %= MOD;
            sum += (m * inv(choose)) % MOD; 
            sum %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}