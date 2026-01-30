/*
2170A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        long long n, k; cin >> n >> k; 
        multiset<long long> q; 
        vector<long long> r(n); 
        for(int i = 0; i < n; ++i){
            long long qi;
            cin >> qi; q.insert(qi); 
        }
        for(int i = 0; i < n; ++i) cin >> r[i];

        sort(r.begin(), r.end(), greater<long long>()); 
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            // max numerator is m * denom + r[i]

            long long denom = r[i] + 1; 
            long long maxQ = (k - r[i])/denom; 
            if (maxQ == 0) continue;
            auto it = q.upper_bound(maxQ);
            if (it != q.begin()) {
                // matched!
                //cout << "Matched " << r[i] << " and " << *prev(it) << " with " << *prev(it) * denom + r[i] << "/" << denom << "\n";
                q.erase(prev(it));
                ++ans; 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}