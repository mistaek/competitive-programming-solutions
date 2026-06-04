/*
2232A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        int curBlock = 0, prev = a[0];
        int ans = 1e9;
        for (int i = 1; i < n; ++i) {
            if (a[i] != prev) {

                // [0, curBlock - 1] are smaller
                // [curBlock, i-1] are equal
                // [i, n-1] are bigger
                int smaller = curBlock;
                int bigger = n-i;

                ans = min(ans, max(smaller, bigger));
                curBlock = i;
                prev = a[i];
            }
        }

        ans = min(ans, curBlock);
        cout << ans << "\n";
    }
    return 0;
}