/*
915D
AC, I'm washed. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
vector<pair<int, int>> cycle; 
vector<vector<int>> g; 
vector<int> vis; 
vector<int> rec; 
int dfsCtr = 1; 
size_t curBan = 0; 
bool cycleFilled = false; 


void trimCycle(){
    reverse(cycle.begin(), cycle.end());
    //cycle[0].first should equal cycle[last].second
    auto it = cycle.begin();
    auto last = cycle.back().second; 
    for(; it < cycle.end(); ++it){
        if(it->first == last){
            cycle = vector<pair<int, int>>(it, cycle.end()); 
            return; 
        }
    }
}
bool isEdgeBanned(int u, int v){
    if(curBan >= cycle.size()) return false; 
    return (u == cycle[curBan].first && v == cycle[curBan].second);
}

bool dfs(int u){
    rec[u] = 1; 
    //cout << u << " " << vis[u] << "\n";
    for(auto v : g[u]){
        if(isEdgeBanned(u, v)) continue;
        if(vis[v] == vis[u] && rec[v]){ // SAME DFS
            if(!cycleFilled) cycle.push_back({u, v}); //push edge into cycle
            return true; 
        }
        //otherwise explore if needed
        if(vis[v] == 0){
            vis[v] = vis[u]; //set value before visiting (?)
            if(dfs(v)){
                if(!cycleFilled) cycle.push_back({u, v}); 
                return true; 
            }
        }
    }
    rec[u] = 0;
    return false; 
} 

int main(){
    int n, m; cin >> n >> m; 
    g = vector<vector<int>>(n+1); 
    vis = vector<int>(n+1, 0);
    rec = vector<int>(n+1, 0);

    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; 
        g[u].push_back(v); 
    }

    //find a cycle 
    for(int i = 1; i <= n; ++i){
        if(vis[i] == 0){
            vis[i] = dfsCtr; 
            if(dfs(i)){
                // cycle is now populated with a path + cycle
                trimCycle(); 

                break; 
            } 
            ++dfsCtr; 
        }
    }
    if(cycle.size() == 0){
        cout << "YES\n"; 
        return 0;
    }    

    cycleFilled = true;
    bool pos = false; 
    for(; curBan < cycle.size(); ++curBan){
        vis = vector<int>(n+1, 0); 
        dfsCtr = 1;

        bool cycleFound = false;  
        for(int i = 1; i <= n; ++i){
            if(vis[i] == 0){
                vis[i] = dfsCtr; 
                if(dfs(i)){
                    cycleFound = true; 
                    break; 
                }
                dfsCtr++;
            }
        }
        if(!cycleFound){
            pos = true; 
            break; 
        }
    }

    if(pos) cout << "YES\n"; 
    else cout << "NO\n";
    return 0;
}