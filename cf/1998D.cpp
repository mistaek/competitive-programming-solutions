/*
1998D
AC
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    int tc; cin >> tc; 
    while(tc--){
        int n, m; cin >> n >> m; 
        vector<vector<int>> g(n+1);
        for(int i = 0; i < m; ++i){
            int u, v; cin >> u >> v; 
            if(u > v) swap(u, v);
            g[u].push_back(v);
        }

        vector<int> ans(n+1, 0), dist(n+1, 1e9);
        dist[0] = 0;
        queue<pair<int, int>> reach; 
        for(int i = 1; i < n; ++i){
            dist[i] = min(dist[i], dist[i-1] + 1); 
            //add edges from i-1
            for(int v : g[i-1]){
                int ndist = dist[i-1] + 1; 
                if(ndist < dist[v]){
                    dist[v] = ndist; 
                    reach.push({v, ndist});
                }
            }

            while(!reach.empty()){
                auto [v, d] = reach.front();
                if(v - i < d) reach.pop();
                else break; 
            }

            ans[i] = reach.empty(); 
            //cout << i << " " << dist[i] << " " << ans[i] << "\n";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}