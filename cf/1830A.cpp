/*
1830A
AC
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<vector<int>> g(n+1); 
        map<pair<int, int>, int> ind; 
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            ind[{min(u, v), max(u, v)}] = i;
            g[u].push_back(v); 
            g[v].push_back(u);
        }
        vector<int> dt(n+1), di(n+1);
        di[1] = n;  
        int ans = 0;
        queue<int> bfs; 
        bfs.push(1); 
        while(!bfs.empty()){

            int u = bfs.front(); 
            bfs.pop(); 
            for(int v : g[u]){
                if(dt[v]) continue; 
                dt[v] = dt[u]; 
                int idx = ind[{min(u, v), max(u, v)}]; 
                di[v] = idx; 
                if(idx < di[u]) dt[v]++;
                ans = max(ans, dt[v]);
                bfs.push(v);
            }
        }
       
        cout << ans << "\n";
    }
    return 0;
}