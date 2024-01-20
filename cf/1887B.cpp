/*
1887B
AC, wonky djikstra
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    int n, t; cin >> n >> t;
    vector<vector<int>> times(t+1); // when does key moment t appear
    vector<vector<pair<int, int>>> g(n+1); //graph 
    for(int i = 1; i <= t; i++){
        int m; cin >> m; 
        for(int j = 0; j< m; j++){
            int u, v; cin >> u >> v; 
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
    }

    int k; cin >> k; 

    for(int i = 1; i <= k; i++){
        int ai; cin >> ai; 
        times[ai].push_back(i);
    }

    vector<int> dist(n+1, 1e9); 
    dist[1] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, 1}); 
    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first; 
        pq.pop();
        if(d > dist[u]) continue; 

        for(auto e : g[u]){
            int v = e.first, rt = e.second; 
            auto search = upper_bound(times[rt].begin(), times[rt].end(), dist[u]);
            if(search == times[rt].end()) continue; 
            int best = *search;
            if(dist[v] > best){
                //cout << v << " " << best << "\n";
                dist[v] = best; 
                pq.push({best, v});
            }
        }
    }

    if(dist[n] == 1e9) cout << -1 << "\n"; 
    else cout << dist[n] << "\n";

    return 0;
}