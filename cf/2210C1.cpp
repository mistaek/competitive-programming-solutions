/*
2210C1
*/

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n), b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        c[0] = gcd(a[0], a[1]);
        c[n-1] = gcd(a[n-1], a[n-2]);
        
        for(int i = 1; i < n-1; ++i) {
            //cout << gcd(a[i-1], a[i]) << " " << gcd(a[i], a[i+1]) << " " << gcd(gcd(a[i-1], a[i]), gcd(a[i], a[i+1])) << "\n";
            c[i] = (gcd(a[i-1], a[i]) * gcd(a[i], a[i+1])) / gcd(gcd(a[i-1], a[i]), gcd(a[i], a[i+1]));
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            //cout << c[i] << "\n";
            if(c[i] != a[i]) ++ans;
        }
        cout << ans << "\n";

    }
    return 0;
}