/*
1009E
*/

#include <iostream>
#include <vector>

using namespace std; 

long long MOD = 998244353;
long long pow(long long a, long long exp){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 60; ++i){
        if(exp & (1LL << i)) ans *= pow; 
        ans %= MOD; 
        pow *= pow; 
        pow %= MOD; 
    }
    return ans; 
}

int main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    vector<int> a(n+1); 
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        long long s = pow(2, n-i);
        s %= MOD; 
        if(n-i-1 >= 0) s += (n-i) *pow(2, n-i-1); 
        s %= MOD; 
        s *= a[i]; 
        s %= MOD; 
        ans += s; 
        ans %= MOD; 
    }

    cout << ans << "\n";




    return 0;
}