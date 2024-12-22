/*
1004E
AC, needed hlep
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

vector<vector<pair<int, int>>> g;
int main(){
    int n, k; cin >> n >> k; 
    g= vector<vector<pair<int, int>>>(n); 

    vector<int> deg, deg1;
    int deg3 = 0;  
    deg = vector<int>(n, 0);
    for(int i = 0; i < n-1; ++i){
        int u, v, d; 
        cin >> u >> v >> d;
        --u, --v; 
        g[u].push_back({v, d}); 
        g[v].push_back({u, d});
    }
    for(int i = 0; i < n; ++i){
        deg[i] = g[i].size(); 
        if(deg[i] >= 3) ++deg3; 
        if(deg[i] == 1) deg1.push_back(i);
    }
    int lo = 0, hi = 1e9;
    while(lo < hi){
        int mid = (lo+hi)/2; 
        vector<int> d = deg;
        vector<int> dist(n, 0); 
        vector<bool> active(n, true);
        queue<int> q; 
        for(auto v : deg1){
            q.push(v);
        }
        int deg3rem = deg3, rem = n; 
        
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int c = -1, curdist; 
            for(auto [v, w] : g[u]){
                if(active[v]){
                    c = v; curdist = dist[u] + w; 
                }
            }
            if(c == -1) continue; 
            if(curdist <= mid){
                //drop u 

                active[u] = false; 
                --rem; 
                dist[c] = max(dist[c], curdist);
                if(d[c] == 3){
                    --deg3rem; 
                }
                --d[c]; 
                //cout << u << " " << c << " " << d[c] << "\n";
                if(d[c] == 1) q.push(c); 
            }
        }
        if(rem <= k && deg3rem == 0) hi = mid; 
        else lo = mid+1; 
    }
    
    cout << lo << "\n";
    return 0;
}