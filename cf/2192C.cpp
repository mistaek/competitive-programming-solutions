/*
2192A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        long long n, h, k; cin >> n >> h >> k;
        long long ans = 0, tot = 0;

        vector<long long> a(n), psum(n, 0), pmin(n, 1e9), smax(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            psum[i] = a[i];
            if(i) psum[i] += psum[i-1];

            pmin[i] = a[i];
            if(i) pmin[i] = min(pmin[i], pmin[i-1]);
        }

        tot = psum[n-1];
        ans += (h/tot) * (n+k);
        h %= tot;
        
        if(h == 0) { ans -= k; cout << ans << "\n"; continue; }

        for(int i = n-1; i >= 0; --i) {
            smax[i] = a[i];
            if(i < n-1) smax[i] = max(smax[i], smax[i+1]);
        }

        long long bp = n-1;
        for(int i = 0; i < n-1; ++i) {
            if (psum[i] >= h) {
                bp = i; break;
            }
            if(psum[i] - pmin[i] + smax[i+1] >= h) {
                bp = i; break;
            }
        }
        cout << ans + bp +1 << "\n";
    }
    return 0;
}