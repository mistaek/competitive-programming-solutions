/*
1462E
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int MOD = 1e9+7; 

int fac[200001], invfac[200001]; 

int binexp(int a, int e){
    int ans = 1, pow = a; 
    for(int i = 0; i < 30; ++i){
        if(e & (1 << i)) ans = 1LL * ans * pow % MOD; 
        pow = 1LL * pow * pow % MOD; 
    }
    return ans; 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    fac[0] = 1;
    for(int i = 1; i <= 200000; ++i) fac[i] = 1LL * fac[i-1] * i % MOD; 
    invfac[200000] = binexp(fac[200000], MOD -2); 
    for(int i = 199999; i >= 0; --i){
        invfac[i] = 1LL * (i+1) * invfac[i+1] % MOD; 
    }
    int t; cin >> t; 
    while(t--){
        int n, m, k; cin >> n >> m >> k; 
        vector<int> a(n); 
        for(int i = 0; i < n; ++i) cin >> a[i]; 
        sort(a.begin(), a.end()); 
        int j = 0; 
        int ans = 0; 
        for(int i = 0; i < n; ++i){
            while(j < n && a[j] - a[i] <= k) ++j; 
            if(j - i < m) continue; 
            //cout << "Range " << i << " " << j-1 << "\n";
            // j - i - 1 choose m - 1 since we are locking in i
            int curans = 1LL * fac[j-i-1] * invfac[m-1] % MOD;
            //cout << j - i - 1 << " " << m -1 << " " << fac[j-i-1] << " " << invfac[m-1] << "\n";
            curans = 1LL *  invfac[j-i-m] * curans % MOD; 
            ans = (ans + curans) % MOD; 
        }
        cout << ans << "\n";
    }
    return 0;
}