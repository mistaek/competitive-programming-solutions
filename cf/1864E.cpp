/*
1864E
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long ans = 0, n, MOD = 998244353;
vector<long long> s; 

long long binexp(long long b, long long pow){
    long long a = b, ret = 1; 
    for(int i = 0; i < 31; i++){
        if(pow & (1LL << i)){
            ret *= a; 
            ret %= MOD; 
        }
        a *= a;
        a %= MOD;
    }
    return ret % MOD; 
}

long long inv(long long a){
    a %= MOD;
    return binexp(a, MOD-2);
}

void solve(int l, int r, int bit){
    if(r < l) return; 
    if(bit == -1){
        ans += 1LL * (r - l + 1) * (r - l + 1);
        ans %= MOD;
        return;
    }
    if(!(s[l] & (1LL << bit)) && !(s[r] & (1LL << bit))){
        solve(l, r, bit-1);
        return; 
    }
    int m = l; 
    for(int i = l+1; i <= r; i++){
        if(!(s[i-1] & (1LL << bit)) && (s[i] & (1LL << bit))){
            m = i; 
            break; 
        }
    }
    int x = m - l, y = r- m + 1; 
    ans += 3LL * x * y; 
    ans += 1LL * y * y;
    ans %= MOD;
    solve(l, m-1, bit-1); 
    solve(m, r, bit - 1); 
}

int main(){
    int t; cin >> t; 
    while(t--){
        cin >> n; 
        ans = 0;
        s = vector<long long>(n); 
        for(int i = 0; i < n; i++) cin >> s[i]; 
        sort(s.begin(), s.end());
        solve(0, n-1, 30);
        //cout << ans << "\n";
        cout << ans * inv(n * n) % MOD << "\n";
    }
    return 0;
}