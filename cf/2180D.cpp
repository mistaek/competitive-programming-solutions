/*
2180D
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> pts(n);
        for(int i = 0; i < n; ++i) cin >> pts[i];
        if(n == 1) {
            cout << 0 << "\n";
            continue;
        }
        int prevmin = 0, prevmax = pts[1] - pts[0];
        int ans = 1;
        for(int i = 1; i < n-1; ++i) {
            int lo = 0, hi = min(pts[i] - pts[i-1], pts[i+1] - pts[i]);
            // if we want to stay connected to the previous 
            int nlo = max(lo, pts[i] - pts[i-1] - prevmax);
            int nhi = min(hi, pts[i] - pts[i-1] - prevmin);

            if(nlo < nhi) {
                ++ans;
                prevmin = nlo;
                prevmax = nhi;
            }
            else {
                prevmin = 0;
                prevmax = pts[i+1] - pts[i];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}