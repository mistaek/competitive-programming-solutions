/*
1900E
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

const long long UN = -1;

vector<long long> c, cc, sz, scc, vis, dfs_low, dfs_num; 
vector<pair<long long, long long>> lp;
stack<int> scc_stack; 
vector<vector<int>> g, cg;
long long dfs_ctr = 0, scc_ctr = 0; 

void lpdfs(int u){
    lp[u] = {sz[u], cc[u]}; 
    long long maxl = 0, maxc = 1e18; 
    for(auto v : cg[u]){
        if(v == u) continue; 
        if(lp[v].first == UN) lpdfs(v); 
        if(lp[v].first > maxl){
            maxl = lp[v].first; 
            maxc = lp[v].second; 
        }
        else if(lp[v].first == maxl){
            maxc = min(maxc, lp[v].second);
        }
    }
    if(maxl){
        lp[u].first += maxl; 
        lp[u].second += maxc; 
    }
}

void sccdfs(int u){
    dfs_low[u] = dfs_num[u] = dfs_ctr++;
    vis[u] = 1; 
    scc_stack.push(u); 
    for(auto v : g[u]){
        if(dfs_num[v] == UN) sccdfs(v); 
        if(vis[v] != UN) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]){
        while(1){
            int v = scc_stack.top(); scc_stack.pop(); 
            vis[v] = UN;
            scc[v] = scc_ctr;
            if(u == v) break; 
        }
        scc_ctr++; 
    }

}

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n,m; cin >> n >> m; 
        c = scc = vis = dfs_low = dfs_num = vector<long long>(n+1, -1); 
        g = vector<vector<int>> (n+1); 
        scc_stack = stack<int>(); 
        dfs_ctr = scc_ctr = 0;

        for(int i = 1; i <= n; i++) cin >> c[i];
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
        }

        for(int i = 1; i <= n; i++){
            if(dfs_num[i] == UN) sccdfs(i);
        }
        cc = sz = vector<long long>(scc_ctr, 0);
        lp = vector<pair<long long, long long>>(scc_ctr, {-1, -1});
        cg = vector<vector<int>>(scc_ctr);
        for(int u = 1; u <= n; u++){
            cc[scc[u]] += c[u]; 
            sz[scc[u]]++; 
            for(auto v : g[u]){
                cg[scc[u]].push_back(scc[v]);
            }
        }

        long long ansl = 0, ansm = 1e18;
        for(int i = 0; i < scc_ctr; i++){
            if(lp[i].first == UN) lpdfs(i);
            if(lp[i].first > ansl){
                ansl = lp[i].first, ansm = lp[i].second; 
            }
            else if(lp[i].first == ansl){
                ansm = min(ansm, lp[i].second);
            }

            //cout << lp[i].first << " " << lp[i].second<< "\n";
        }
        cout << ansl << " " <<  ansm << "\n";



    }
    return 0;
}