/*
999E
AC
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

vector<vector<int>> g, sccs, g2; 
vector<pair<int, int>> e; 
vector<int> vis, hi, low, sccmp; 
stack<int> s; 

int dfsCtr = 1; 
const int UNVIS = -1; 

void tarjanSCC(int u){
    hi[u] = low[u] = dfsCtr++; 
    s.push(u); 
    vis[u] = 1; 

    for(auto v : g[u]){
        if(hi[v] == UNVIS) tarjanSCC(v);
        if(vis[v]) low[u] = min(low[u], low[v]); 
    }

    //root of scc
    if(hi[u] == low[u]){
        sccs.push_back(vector<int>());
        while(1){
            int v = s.top(); s.pop(); 
            sccs.back().push_back(v); 
            sccmp[v] = (int)sccs.size() - 1; 
            vis[v] = 0;
            if(u == v) break; 
        } 
    }
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int n, m, capital; 
    cin >> n >> m >> capital; 
    g = vector<vector<int>> (n);
    vis = vector<int>(n, 0);
    sccmp = hi = low = vector<int>(n, UNVIS); 

    --capital; 
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; 
        --u; --v; 
        g[u].push_back(v); 
        e.push_back({u, v});
    }

    for(int i = 0; i < n; ++i){
        if(low[i] == UNVIS) tarjanSCC(i);
    }

    g2 = vector<vector<int>>(sccs.size()); 

    for(auto [u, v] : e){
        if(sccmp[u] != sccmp[v]) g2[sccmp[v]].push_back(sccmp[u]);
    }

    int ans = 0;

    for(int i = 0; i < sccs.size(); ++i){
        if(g2[i].size() == 0 && i != sccmp[capital]) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}