/*
2226D
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), sorted;
        for(int i = 0; i < n; ++i) cin >> a[i];

        sorted = a;
        sort(sorted.begin(), sorted.end());
        if (sorted[0] % 2 != sorted[n-1] % 2) {
            cout << "YES\n";
            continue;
        }

        set<pair<int, int>> inner, outer;
        for(int i = 0; i < n; ++i) {
            if (a[i] % 2) inner.insert({a[i], i});
            else outer.insert({a[i], i});
        }

        if (sorted[0] % 2) inner.swap(outer);
        if (inner.empty()) {
            bool good = true;
            for(int i = 0; i < n; ++i){
                if (sorted[i] != a[i]) {
                    good = false;
                }
            }
            if (good) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        int maxmin = 0, minmax = n-1;
        for(auto [ai, i] : outer) {
            if (ai > inner.begin()->first) break;
            maxmin = max(maxmin, i);
        }

        for (auto it = outer.rbegin(); it != outer.rend(); ++it) {
            if (it->first < inner.rbegin()->first) break;
            minmax = min(minmax, it->second);
        }

        if (minmax < maxmin) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}