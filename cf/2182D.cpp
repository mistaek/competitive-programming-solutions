/*
2182D
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long long MOD = 998244353;

long long binexp(long long a, long long b) {
    long long pow = a, ans = 1;
    for(int i = 0; i < 60; ++i){
        if(b & (1LL << i))
            ans *= pow;
        ans %= MOD;
        pow *= pow;
        pow %= MOD;
    }
    return ans;
}
vector<long long> fac(1e6+1, 0);
vector<long long> inv(1e6+1, 0);
int main() {
    fac[0] = 1; inv[0] = 1;
    for(long long i = 1; i <= 1e6; ++i) {
        fac[i] = i * fac[i-1];
        fac[i] %= MOD;
    }
    inv[1e6] = binexp(fac[1e6], MOD - 2);
    for(long long i = 1e6 - 1; i >= 1; --i) {
        inv[i] = (i+1) * inv[i+1];
        inv[i] %= MOD;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int s; vector<int> a(n);
        cin >> s;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int>());

        int fb = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == a[0]) ++fb;
            if(a[i] < a[0] - 1) {
                s -= a[0]-1-a[i];
                a[i] = a[0]-1;
            }
        }

        if(s < 0){
            cout << "0\n";
            continue;
        }
        // answer is fac(fb + s) * fac(n - fb)
        long long left = fb + min(s, n - fb);
        long long right = n-fb - min(s, n -fb);

        cout << (fac[left] * fac[right] % MOD) * (fac[n-fb] * inv[min(s, n-fb)] % MOD) % MOD * inv[n-fb - min(s, n-fb)] % MOD << "\n";
    }
    return 0;
}