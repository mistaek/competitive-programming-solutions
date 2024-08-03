/*
1817B
AC, yuck
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std; 

vector<vector<int>> g; 
vector<int> cycle, vis, p;
int origin; 
bool found = false; 

bool dfs(int u){
    if(vis[u] && u == origin){
        if(!found){
            found = true; 
            cycle.push_back(u); 
            return true; 
        }
        return false; 
    }
    if(vis[u]) return false; 
    vis[u] = true; 
    //cout << u<< "\n";

    for(auto v : g[u]){
        if(!vis[v] || (v == origin && p[u] != origin)){
            p[v] = u; 
            if(dfs(v)){
                cycle.push_back(u); 
                return true; 
            }
        }
    }
    return false; 
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
//    int ctr = 1, out = 0;
    while(t--){
        int n, m; cin >> n >> m; 
        //if(out) cout << n << " " << m <<"\n";
        g = vector<vector<int>>(n+1);
        cycle.clear(); 
        found = false; 
        for(int i = 0; i < m; ++i){
            int u, v; cin >> u >> v; 
            //if(out) cout << u << " " << v << "\n";
            g[v].push_back(u); 
            g[u].push_back(v);
        }

        for(int i = 1; i <= n; ++i){
            if(g[i].size() >=4){
                p = vis = vector<int>(n+1, 0);
                origin = i; 
                dfs(i);
                if(found){
                    break; 
                }
            }
        }
        //if(!out && ctr >= 5) continue;
        if(found){
            cout << "YES\n";
            set<int> incycle; 
            int start = 1; 
            for(int i = 1; i < cycle.size() - 2; ++i){
                for(auto v : g[origin]){
                    if(v == cycle[i]) start = i; 
                }
            }
            cout << cycle.size() - start + 2 << "\n"; 
            cout << origin << " " << cycle[start] << "\n"; 
            for(int i = start; i < cycle.size() - 1; ++i){
                cout << cycle[i] << " " << cycle[i+1] << "\n"; 
                incycle.insert(cycle[i]);
                incycle.insert(cycle[i+1]);
            }
            int cnt = 0; 
            for(auto v : g[origin]){
                if(incycle.find(v) == incycle.end()){
                    cout << v << " " << origin << "\n";
                    ++cnt; 
                }
                if(cnt == 2) break; 
            }
        }
        else cout << "NO\n";
    }

    return 0;
}