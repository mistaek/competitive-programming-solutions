/*
2211C
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
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        vector<int> acnt(n+1, 0), bcnt(n+1, 0);
        multiset<int> filled;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        bool possible = true;
        int avail = 0;

        // initial counting
        for(int i = 0; i < k; ++i) acnt[a[i]]++;
        for(int i = 0; i < k; ++i){ 
            if(b[i] != -1) bcnt[b[i]]++;
            else avail++;
        }

        for(int i = 1; i <= n; ++i) {
            while(acnt[i] > bcnt[i]){
                if(avail == 0) {
                    possible = false; break;
                }
                --avail;
                filled.insert(i);
                bcnt[i]++;
            }
            if(acnt[i] < bcnt[i]){
                possible = false; break;
            }
        }

        if(!possible){
            cout << "NO\n";
            continue;
        }

        for(int i = k; i < n; ++i) {
            // at start of loop iter, b is rearrangement of a
            acnt[a[i-k]]--; acnt[a[i]]++;
            bool canRemove = false, canAdd = false;
            if(b[i-k] != -1) {
                bcnt[b[i-k]]--;
            }
            else canRemove = true;

            if(b[i] != -1){
                bcnt[b[i]]++;
            }
            else {
                canAdd = true;
            }

            // check possibilities
            if (bcnt[a[i-k]] > acnt[a[i-k]]) {
                // happens if
                // 1. a[i-k] != a[i] AND b[i-k] != a[i-k]
                // 2. a[i-k] == a[i] AND b[i] == a[i-k]
                // In both cases, need b[i-k] == -1 to remove a[i-k]
                // If b[i] == a[i-k] in case 1, impossible to recover. 
                if (canRemove && filled.find(a[i-k]) != filled.end()) {
                    bcnt[a[i-k]]--;
                    filled.erase(filled.find(a[i-k]));
                    canRemove = false;
                }
            }
            if(bcnt[a[i]] < acnt[a[i]]) {
                // happens if
                // 1. a[i-k] != a[i] AND b[i] != a[i]
                // 2. a[i-k] == a[i] AND b[i-k] == a[i]
                // Need b[i] == -1 to add a[i]
                // If b[i-k] == a[i] then it is impossible to recover
                if (canAdd) {
                    b[i] = a[i];
                    bcnt[a[i]]++;
                    canAdd = false;
                }
            }
            if(b[i-k] != -1 && acnt[b[i-k]] > bcnt[b[i-k]]) {
                // Need to add back a b[i-k] in this spot specifically
                // Don't use filled set.
                if(canAdd) {
                    b[i] = b[i-k];
                    bcnt[b[i-k]]++;
                    canAdd = false;
                }
            }
            if(b[i] != -1 && acnt[b[i]] < bcnt[b[i]]) {
                if(canRemove && filled.find(b[i]) != filled.end()) {
                    filled.erase(filled.find(b[i]));
                    bcnt[b[i]]--;
                    canRemove = false;
                }
            }
            // it is possible for a[i] == a[i-k] and b[i] == b[i-k] in which case nothing changes (?)
            if(bcnt[a[i-k]] != acnt[a[i-k]] || bcnt[a[i]] != acnt[a[i]] || (b[i] != -1 && acnt[b[i]] != bcnt[b[i]]) || (b[i-k] != -1 && acnt[b[i-k]] != bcnt[b[i-k]])) {
                possible = false;
                break;
            }
        }
        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }    
    return 0; 
}