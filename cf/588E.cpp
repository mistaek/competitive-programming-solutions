/*
588E
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 

using namespace std; 
constexpr int LOG = 18, MAXPPL=10, MAXN = 1e5+1; 

vector<int> g[MAXN];
int blift[MAXN][LOG]; 
vector<int> ppl[MAXN][LOG];
int depth[MAXN]; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n, m, q; cin >> n >> m >> q; 


    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    for(int i = 1; i <= m; ++i){
        int ci; cin >> ci; 
        ppl[ci][0].push_back(i);
        if(ppl[ci][0].size() > MAXPPL) ppl[ci][0].pop_back();
    }

    // we will arbitrarily root the tree at 1
    auto dfs = [&](auto self, int u, int p) -> void{
        //traverse children
        for(auto v : g[u]){
            if(v == p) continue; 
            blift[v][0] = u; 
            depth[v] = depth[u] + 1; 
            self(self, v, u); 
        }
    };
    dfs(dfs, 1, 0);
    //build lift
    auto mergePPL = [&](const vector<int>& s1, const vector<int>& s2){
        vector<int> un; 
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(un), less<int>());
        while(un.size() > MAXPPL) un.pop_back(); 
        return un;
    };
    for(int k = 1; k < LOG; ++k){
        for(int i = 1; i <= n; ++i){
            blift[i][k] = blift[blift[i][k-1]][k-1]; 
            ppl[i][k] = mergePPL(ppl[i][k-1], ppl[blift[i][k-1]][k-1]);
            while(ppl[i][k].size() > MAXPPL) ppl[i][k].pop_back();
        }
    }
    auto getAncestor = [&](int u, int k){
        int cur = u; 
        for(int i = LOG-1; i >= 0; --i){
            if(k & (1 << i)) cur = blift[cur][i];  
        }
        return cur; 
    };
    auto getPPL = [&](int u, int k){
        // get the best ppl from u to its k-th ancestor (inclusive)
        int cur = u;
        vector<int> res;
        for(int i = LOG -1; i >= 0; --i){
            if((k+1) & (1 << i)){
                res = mergePPL(res, ppl[cur][i]);
                cur = blift[cur][i];
            }
        }
        return res; 
    };

    auto LCA = [&](int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        v = getAncestor(v, depth[v] - depth[u]); 
        //binary search for highest element where they are still unequal
        if(u == v) return u; 
        for(int i = LOG-1; i >= 0; --i){
            if(blift[u][i] != blift[v][i]){
                u = blift[u][i]; 
                v = blift[v][i];
            }
        }
        return blift[u][0]; 
    };
    
    for(int i = 0; i < q; ++i){
        int u, v, a; 
        cin >> u >> v >> a; 
        vector<int> un; 
        int lca = LCA(u, v); 
        un = getPPL(u, depth[u] - depth[lca]);
        un = mergePPL(un, getPPL(v, depth[v] - depth[lca]));  
        int toOut = min((int) un.size(), a); 
        cout << toOut; 
        for(int j = 0; j < toOut; ++j){
            cout << " "; 
            cout << un[j]; 
        }
        cout << "\n"; 
    }
    return 0;
}