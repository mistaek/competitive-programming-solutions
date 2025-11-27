/*
1176E
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std; 
//educated guess.. 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        vector<set<int>> g(n); 
        set<pair<int, int>, greater<pair<int, int>>> pq; 
        vector<bool> rem(n, 0); 
        for(int i = 0; i < m; ++i){
            int u, v; cin >> u >> v; 
            --u, --v; 
            g[u].insert(v); 
            g[v].insert(u); 
        }
        for(int i = 0; i < n; ++i){
            pq.insert({g[i].size(), i}); 
        }

        vector<int> out; 
        while(!pq.empty()) {
            auto [d, u] = *pq.begin(); 
            pq.erase(pq.begin()); 
            if(rem[u]) continue; 
            if(d != g[u].size()) {
                pq.insert({g[u].size(), u}); 
                continue; 
            }
            rem[u] = 1; 
            out.push_back(u); 
            for(auto v : g[u]){
                if(rem[v]) continue; 
                rem[v] = true; 
                for(auto c : g[v]){
                    if(c == u) continue; 
                    g[c].erase(v); 
                }
            }
        }

        if(out.size() <= n/2){
            cout << out.size() << "\n";
            for(int i = 0; i < out.size(); ++i){
                if(i) cout << " "; 
                cout << out[i] + 1;
            }
        }
        else {
            bool outed[n] = {}; 
            for(int i = 0; i < out.size(); ++i){
                outed[out[i]] = 1; 
            }
            cout << n - out.size() << "\n"; 
            for(int i = 0; i < n; ++i){
                if(!outed[i]) cout << i+1 << " "; 
            }
        }

        cout <<"\n";
    }
    return 0;
}