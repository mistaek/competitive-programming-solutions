/*
2182E
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

int main(){ 
    int t; cin >> t;
    while(t--) {
        long long n, m, k; cin >> n >> m >> k;
        multiset<int> a;
        for(int i = 0; i < m; ++i) {
            int ai; cin >> ai;
            a.insert(ai);
        }

        vector<pair<long long, long long>> xzy;
        vector<bool> pleased(n, 0);
        for(int i = 0; i < n; ++i){
            int x, y, z; cin >> x >> y >> z;
            k-=y;
            xzy.push_back({z-y, x});
        }

        int ans = 0;
        sort(xzy.begin(), xzy.end());
        for(int i = n - 1; i >= 0; --i) {
            auto it = a.lower_bound(xzy[i].second);
            if(it != a.end()){
                ++ans;
                pleased[i] = true;
                a.erase(it);
            }
        }
        for(int i = 0; i < n; ++i){
            if(k == 0) break;
            if(pleased[i]) continue;
            if(xzy[i].first <= k){
                ++ans;
                k-=xzy[i].first;
                pleased[i] = true;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}