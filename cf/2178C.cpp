/*
2178C
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<long long> a(n), suf(n, 0), pref(n, 0);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = n-1; i >= 0; --i) {
            if(i < n-1) suf[i] += suf[i+1];
            suf[i] -= a[i];
        }
        pref[0] += a[0];
        for(int i = 1; i < n; ++i){
            pref[i] += pref[i-1];
            pref[i] += max(a[i], -a[i]);
        }

        long long ans = suf[1];
        for(int i = 0; i < n; ++i){
            long long localans = 0;
            if(i) localans += pref[i-1];
            if(i < n-1) localans += suf[i+1];
            ans = max(ans, localans);
        }

        cout << ans << "\n";
    }
    return 0;
}