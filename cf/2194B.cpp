/*
2194A
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
        long long n, x, y; cin >> n >> x >> y;
        vector<long long> a(n);
        long long transfertotal = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            transfertotal += y * (a[i]/x);
        }

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, transfertotal + a[i] - (y*(a[i]/x)));
        }

        cout << ans << "\n";        
    }
    return 0;
}