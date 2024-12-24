/*
1006E
AC
*/

#include <iostream>
#include <set> 
#include <vector>

using namespace std; 

vector<set<int>> g; 
vector<int> seq, id, sz;

void dfs(int u){
    id[u] = seq.size(); 
    sz[u] = 1; //number of vertices in subtree
    seq.push_back(u); 
    for(auto c : g[u]){
        dfs(c);
        sz[u] += sz[c];
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, q; cin >> n >> q; 
    g = vector<set<int>>(n+1);
    sz = id = vector<int>(n+1, 0);
    for(int i = 2; i <= n; ++i){
        int p; cin >> p;
        g[p].insert(i);
    }
    dfs(1);

    for(int i = 0; i < q; ++i){
        int u, k; cin >> u >> k;
        if(k > sz[u]) cout << "-1\n"; 
        else{
            cout << seq[id[u] + k-1] << "\n"; 
        }
    }
    return 0;
}