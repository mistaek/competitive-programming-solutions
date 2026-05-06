/*
2210B
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        set<int> cur;
        int ans = 0, curans = 0;
        for (int i = 1; i <= n; ++i) {
            int c; cin >> c;
            if (i == *cur.begin()) {
                cur.erase(cur.begin());
                --curans;
            }
            if (c > i) {
                cur.insert(c); 
            } 
            ++curans;
            ans = max(ans, curans);
        }
        cout << ans << "\n";
    }
    return 0;
}