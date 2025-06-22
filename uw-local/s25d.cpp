/*
s25d
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int c; cin >> c; 
    while(c--){
        int n; cin >> n; 
        vector<vector<int>> g(n); 
        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u); 
        }
        
        auto bfs = [&](int u){
            queue<int> bfs;
            vector<int> vis(n, -1); 
            vis[u] = 0; 
            bfs.push(u); 
            pair<int, int> ans = {u, 0};
            while(!bfs.empty()){
                int x = bfs.front(); 
                bfs.pop(); 
                for(auto y : g[x]){
                    if(vis[y] == -1){
                        vis[y] = vis[x] + 1; 
                        bfs.push(y); 
                        if(vis[y] > ans.second){
                            ans = {y, vis[y]}; 
                        }
                    }
                }
            }
            return ans; 
        };

        pair<int, int> a = bfs(0); 
        a = bfs(a.first); 
        cout << (a.second + 1)/2 << "\n"; 
        

        

    }
    return 0;
}