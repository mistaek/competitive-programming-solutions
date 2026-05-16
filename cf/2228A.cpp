/*
2228A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0;
        int ones = 0, twos = 0;
        for(int i = 0; i < n; ++i) {
            int w; cin >> w;
            if (w == 0) ++ans;
            else if (w == 1) ++ones;
            else ++twos;
        }
        int aa = min(ones, twos);
        ones -= aa;
        twos -= aa;
        ans += aa;

        ans += ones/3;
        ans += twos/3;
        cout << ans << "\n";

    }
    return 0;
}