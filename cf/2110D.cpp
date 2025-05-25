/*
2110D
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        vector<vector<pair<int, int>>> g(n+1); 
        vector<int> b(n+1);
        // indegree, batteries takable at i, batteries taken when reaching t
        for(int i = 1; i <= n; ++i){
            cin >> b[i];
        }
        for(int i = 0; i < m; ++i){
            int s, tv, w; cin >> s >> tv >> w; 
            g[s].push_back({tv, w});
        }

        int lo = 0, hi = 1e9+1; 
        while(lo < hi){
            int mid = (hi+lo)/2; //maximal allowed batteries
            vector<int> t(n+1, -1); //max amount when reaching index i
            t[1] = 0;
            bool pos = false; 
            for(int i = 1; i <= n; ++i){
                if(t[i] == -1) continue; 
                for(auto [v, w] : g[i]){
                    if(w > mid) continue; // unusable passage since we can have at most mid batteris
                    if(min(mid, b[i] + t[i]) >= w){ //can use b[i] + t[i] total
                        if(v == n) pos = true; 
                        t[v] = max(t[v], min(mid, t[i] + b[i])); 
                    }
                }
            }
            if(pos) hi = mid; 
            else lo = mid+1; 
        }

        if(lo == 1e9+1) cout << "-1\n"; 
        else cout << lo << "\n";
        
    }
    return 0;
}