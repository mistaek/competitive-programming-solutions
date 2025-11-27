/*
1174F
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
    
using namespace std;
    
const int N = 200005;
int lift[N][19] = {}; 
    
int main(){
    int n; cin >> n; 
    vector<vector<int>> g(n+1);
    
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u); 
    }
    
    vector<int> sz(n+1, 0), depth(n+1, 0), head(n+1, 0), tail(n+1, 0); //head and tail of the current heavy path
    int dist;
    cout << "d " << 1 << endl; 
    cin >> dist;
    
    
    auto dfs_sz = [&](auto self, int u, int p) -> void{
        if(depth[u] == dist) ++sz[u];
        for(auto c : g[u]){
            if(c == p) continue; 
            depth[c] = depth[u] + 1; 
            lift[c][0] = u; 
            self(self, c, u); 
            sz[u] += sz[c]; 
        }
    };
    
    auto dfs_hld = [&](auto self, int u, int h, int p) -> void{
        head[u] = h; 
        tail[u] = u; 
        int hc = -1; 
        for(auto c : g[u]){
            if(c == p) continue; 
            if(hc == -1 || sz[c] > sz[hc]){
                hc = c; 
            }
        }
    
        if(hc != -1){
            self(self, hc, h, u); 
            tail[u] = tail[hc];
        }
        for(auto c : g[u]){
            if(c == p || c == hc) continue; 
            self(self, c, c, u); 
        }
    };
    dfs_sz(dfs_sz, 1, 1);
    dfs_hld(dfs_hld, 1, 1, 1);
    
    for(int k = 1; k <= 18; ++k){
        for(int i = 1; i<= n; ++i){
            lift[i][k] = lift[lift[i][k-1]][k-1]; 
        }
    }
    
    auto getKth = [](int u, int k){
        int ans = u; 
        for(int i = 0; i <= 18; ++i){
            if(k & (1 << i)) ans = lift[ans][i];
        }
        return ans; 
    };
    
    int cur = 1, curdist = dist; 
    while(curdist){
        int curToTail = depth[tail[cur]] - depth[cur];
        int tailToSpot;
        cout << "d " << tail[cur] << endl; 
        cin >> tailToSpot; 
        int goUp = (tailToSpot - curdist + curToTail)/2; 
        cur = getKth(tail[cur], goUp); 
        curdist = (curdist + tailToSpot - curToTail)/2;  
        if(curdist == 0) break; 
        cout << "s " << getKth(tail[cur], goUp) << endl;
        cin >> cur; 
        curdist--; 
    }
    
    cout << "! " << cur << "\n"; 
    
    
    return 0;
}