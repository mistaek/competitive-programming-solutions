/*
1805D
AC
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std; 
int n; 
vector<vector<int>> g; 
vector<int> dist, vis, ans; 

void dfs(int u){
    vis[u] = 1; 
    for(auto v : g[u]){
        if(!vis[v]){
            dist[v] = dist[u] + 1; 
            dfs(v); 
        }
    }
}
pair<int, int> getmx(){
    int maxd = 0, maxi = 1;
    for(int i = 1; i <= n; ++i){
        if(dist[i] > maxd){
            maxd = dist[i]; 
            maxi = i; 
        }
    }
    return {maxd, maxi};
}

void clear(){
    dist = vector<int>(n+1, 0); 
    vis = vector<int>(n+1, 0);
}

int main(){
    cin >> n;
    g = vector<vector<int>>(n+1); 
    ans = vis = dist = vector<int>(n+1, 0);

    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        g[u].push_back(v); g[v].push_back(u); 
    }

    //find diam and add to q
    dfs(1); 

    auto [mxd, mxi] = getmx();
    clear();
    dfs(mxi); 
    
    priority_queue<pair<int, int>> q;
    auto [mxd1, mxi1] = getmx();
    for(int i = 1; i<= n; ++i){
        q.push({dist[i], i});
    }

    clear(); 
    dfs(mxi1); 

    for(int i = 1; i <= n; ++i){
        q.push({dist[i], i});
    }
    clear();
    //drop dist to 1 
    for(int i = n; i >= 1; --i){
        if(i > mxd1){
            ans[i] = n; 
            continue; 
        }
        else{
            ans[i] = n+1; 
            break; 
        }  
    }
    int curd = mxd1; 
    while(!q.empty()){
        auto [du, u] = q.top(); 
        q.pop();
        if(vis[u]) continue; 
        vis[u] = 1; 
        if(curd != du){
            curd = du; 
            ans[du] = ans[du+1]; 
        }
        --ans[curd];
    }
    while(--curd){
        ans[curd] = ans[curd+1];
    }

    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}