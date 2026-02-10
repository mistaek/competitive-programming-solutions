/*
2188C
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n), sorted;
        for(int i = 0; i < n; ++i) cin >> a[i];
        sorted=a;
        sort(sorted.begin(), sorted.end());
        long long ans = 1e15;
        for(int i = 0; i < n; ++i) {
            if(sorted[i] != a[i]) {
                long long tempans = abs(sorted[i] - a[i]);
                tempans = max(tempans, min(max(abs(sorted[i] - sorted[0]), abs(sorted[i] - sorted[n-1])), max(abs(a[i] - sorted[n-1]), abs(a[i] - sorted[0]))));
                ans = min(ans, tempans);
            }
        }
        if(ans == 1e15) {
            cout << "-1\n";
        }
        else cout << ans << "\n";
    }
    return 0;
}