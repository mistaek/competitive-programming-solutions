/*
1130
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> g; 
vector<int> maxMatch[2];
//max match = max cover
// dp[0][i] = max match in subtree, i is not by parent
// dp[1][i] = max match in subtree, i is taken 
void dfs(int u, int prev){
    int sum = 0; 
    for(auto v : g[u]){
        if(v != prev){
            dfs(v, u); 
            sum +=maxMatch[0][v]; 
            maxMatch[1][u] += maxMatch[0][v]; // can only take type 0 subtrees
        }
    }

    maxMatch[0][u] = sum; 
    for(auto v : g[u]){
        if(v != prev){
            //consider taking this edge
            maxMatch[0][u] = max(maxMatch[0][u], 1 + sum - maxMatch[0][v] + maxMatch[1][v]); 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n; cin >> n; 
    g = vector<vector<int>>(n+1); 
    maxMatch[0] = maxMatch[1] = vector<int>(n+1, 0); 
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        g[v].push_back(u); 
        g[u].push_back(v);
    }    
    dfs(1, 1); 

    cout << max(maxMatch[0][1], maxMatch[1][1]) << "\n";
    return 0;
}