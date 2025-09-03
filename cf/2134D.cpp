/*
2134E
*/
    
#include <iostream>
#include <vector>
    
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<vector<int>> g(n+1); 
        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<int> dist(n+1, 0); 
        auto dfs = [&](auto self, int u, int p) -> void{
            for(auto c : g[u]){
                if(c != p){
                    dist[c] = 1 + dist[u]; 
                    self(self, c, u); 
                }
            }
        };
        dfs(dfs, 1, 1); 
        int endP = 1; 
        for(int i = 1; i<= n; ++i){
            if(dist[i] > dist[endP]){
                endP = i; 
            }
        }
        dist = vector<int>(n+1, 0); 
        dfs(dfs, endP, endP);
         
        int endP2 = 1; 
        for(int i = 1; i <= n; ++i){
            if(dist[i] > dist[endP2]) endP2 = i; 
        }

        if(dist[endP2] == n-1){
            cout << -1 << "\n"; 
            continue;
        }
        vector<int> og = std::move(dist); 
        dist = vector<int>(n+1, 0); 
        // diameter is endP -> endP2
        dfs(dfs, endP2, endP2); 
        
        int cur = endP, last = cur; 
        int a, b, c; 
        while(true){
            int next = cur, branch = cur; 
            for(auto c : g[cur]){
                if(c != last){
                    if(dist[c] == dist[cur] - 1){
                        next = c; 
                    }
                    else{
                        branch = c; 
                    }
                }
            }
            if(branch != cur){
                a = last, b = cur, c = branch; 
                break; 
            }
            last = cur;
            cur = next; 
        }
        cout << a << " " << b << " " << c << "\n"; 

    }
    return 0;
}