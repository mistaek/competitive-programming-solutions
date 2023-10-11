/*
1873H
annoyign graph problem, idk whats going on in my code but it works :blobthumbsup:
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

void dfs(int v, vector<int> &dist, vector<vector<int>> &g, int p, int &targ){
    for(int u : g[v]){
        if(targ != -1) return; 

        if(dist[u] != -1 && u != p){
            targ = u;
            return; 
        }
        else if(dist[u] == -1){
            dist[u] = dist[v]+1; 
            dfs(u, dist, g, v, targ);
        }
    }
} 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        int n, a, b; cin >> n >> a >> b; 
        a--; b--;
        vector<vector<int>> g(n); 

        for(int i = 0; i < n; i++){
            int u, v; cin >> u >> v; 
            u--; v--;
            g[u].push_back(v); 
            g[v].push_back(u);
        }
        int targ = -1; 
        vector<int> dist(n, -1);
        dist[b] = 0;
        dfs(b, dist, g, -1, targ);

        vector<int> vis(n, -1); 
        vis[a] = 0;
        queue<pair<int, int>> bfs; 
        bfs.push({a, 0});
        while(!bfs.empty()){
            int v = bfs.front().first, d = bfs.front().second;
            bfs.pop();

            for(int u : g[v]){
                if(vis[u] == -1){
                    vis[u] = d+1; 
                    bfs.push({u, d+1});
                }
            }
        }
        //cout << targ << " " << dist[targ] << " " << vis[targ] << "\n";

        if(vis[targ] <= dist[targ]){
            cout << "NO\n"; 
        }
        else cout << "YES\n";
    }
    return 0;
}