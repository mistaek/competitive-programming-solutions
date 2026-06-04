/*
2208A
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> cnt(n*n + 1, 0);

        bool pos = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int c; cin >> c;
                cnt[c]++;
                if (cnt[c] > n * n - n) pos = false;
            }
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}