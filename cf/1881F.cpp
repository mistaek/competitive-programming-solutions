/*
1881F
AC
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

vector<vector<int>> g; 
vector<int> dd, md, mrk; 
vector<int> p; 
vector<pair<int, int>> tp2; //top 2 children

void dfs(int u){
    //computes downward optimal
    if(mrk[u]) dd[u] = 0;
    for(int v : g[u]){
        if(v == p[u]) continue; 
        p[v] = u;
        dfs(v); 
        if(dd[v] != -1){
            dd[u] = max(dd[u], 1 + dd[v]);
            if(dd[v] >= dd[tp2[u].first]){
                tp2[u].second = tp2[u].first;
                tp2[u].first = v; 
            }
            else if(dd[v] > dd[tp2[u].second]) tp2[u].second = v; 
        }
    }
}

void bfs(){
    queue<int> q; 
    q.push(1); 
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(v == p[u]) continue; 
            q.push(v);
            if(mrk[v]) md[v] = 0; 
            if(mrk[u]) md[v] = 1;
            if(v == tp2[u].first){
                md[v] = max(md[v], 2 + dd[tp2[u].second]); // go UP one
                
            }
            else{
                md[v] = max(md[v], 2 + dd[tp2[u].first]);
            }
            if(md[u] >= 0) md[v] = max(md[v], 1 + md[u]); 
        }
    }
    
}

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        g = vector<vector<int>>(n+1); 
        dd = md = vector<int>(n+1, -1), p = mrk = vector<int>(n+1, 0);
        tp2=vector<pair<int,int>>(n+1, {0,0});
        dd[0] = -1e9; //safety
        for(int i = 0; i < k; i++){
            int ai; cin >> ai; 
            mrk[ai] = 1; 
        }
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); g[v].push_back(u);
        }
        
        dfs(1);
        md[1] = -1e9; 
        bfs();
        int ans = 1e9; 
        for(int i = 1; i <= n; i++){
            //cout << i << " " << dd[i] << " " << md[i] << "\n";
            //cout << tp2[i].first << " " << tp2[i].second << "\n";
            ans = min(ans, max(dd[i], md[i]));
        }
        cout << ans << "\n";
    }
    return 0;   
}