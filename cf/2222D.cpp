/*
2222D
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
        int n; cin >> n;
        vector<long long> a(n), ans(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<pair<long long, int>> b(n);
        b[0] = {0, 0};
        for(int i = 1; i < n; ++i){
            b[i] = {b[i-1].first + a[i-1], i};
        }

        sort(b.begin(), b.end());
        for(int i = 0; i < n; ++i) {
            //cout << b[i].first << " " << b[i].second << " " << n-i << "\n";
            ans[b[i].second] = n-i;
        }

        for(int i = 0; i < n; ++i){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}