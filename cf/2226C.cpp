/*
2226B
*/
 
#include <iostream>
#include <vector>
#include <set>
 
#include <ctime>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t;
    int ctr = 0;
    while(t--){
        ++ctr; 
        int n; cin >> n;
        multiset<int> ao, dupo;
        for(int i = 0; i < n; ++i) {
            int ai; cin >> ai;
            if (ao.find(ai) == ao.end()) ao.insert(ai);
            else dupo.insert(ai);
        }
 
        int lo = 0, hi = n; 
        while(lo < hi) {
            multiset<int> a, dup;
            a = ao;
            dup = dupo;
            int m = (lo + hi + 1)/2;
            int ans = 0; 
            while(true) {
                while(!a.empty() && *a.begin() < ans) a.erase(a.begin());
                while(!dup.empty() && *dup.begin() < ans) dup.erase(dup.begin());
                if (a.empty() && dup.empty()) break;
                auto it = dup.upper_bound(2*ans);
                auto it2 = a.upper_bound(max(2*ans, m-1));
                if (*a.begin() == ans) {
                    a.erase(a.begin());
                    ++ans; 
                }
                else if (it != dup.end() && it2 != a.end()) {
                    if (*it2 < *it) a.erase(it2);
                    else dup.erase(it);
                    ++ans;
                }
                else if (it != dup.end()) {
                    ++ans;
                    dup.erase(it);
                }
                else if (it2 != a.end()) {
                    a.erase(it2);
                    ++ans;
                }
                else break;
            }
            if (ans >= m) lo = m; 
            else hi = m-1;
        }
 
        cout << lo << "\n";
    }
    return 0;
}