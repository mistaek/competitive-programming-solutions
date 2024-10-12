/*
938D
AC, learned pq thing.
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n, m; cin >> n >> m; 
    vector<vector<pair<long long, long long>>> g(n+1);
    vector<long long> dist(n+1);
    set<pair<long long, long long>> pq; 

    for(int i = 0; i < m; ++i){
        long long u, v, w; cin >> u >> v >> w; 
        g[u].push_back({v, w}); 
        g[v].push_back({u, w});
    }

    for(int i = 1; i <= n; ++i){
        cin >> dist[i];
        pq.insert({dist[i], i});
    }

    while(!pq.empty()){
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        for(auto [v, w] : g[u]){
            if(d + 2*w < dist[v]){
                pq.erase({dist[v], v});
                dist[v] = d+2*w; 
                pq.insert({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(i-1) cout << " "; 
        cout << dist[i]; 
    }
    cout << "\n";

    return 0;
}