/*
2057B
*/

#include <iostream>
#include <map>
#include <set>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        map<int, int> cnt;
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            cnt[a]++;
        }
        set<pair<int, int>> q;
        for(auto [k, v] : cnt){
            q.insert({v, k}); 
        }


        auto it = q.begin(); 
        int sub = 0; 
        while(true){
            if(next(it) == q.end()) break; // leave last element alone
            if(it->first <= k){
                k -= it->first; //change to the last value
                sub++; 
            }
            it++;
        }

        cout << (int)q.size() - sub << "\n"; 

    }
    return 0;
}