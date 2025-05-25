/*
1156D
tree dp, tricky
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    vector<vector<pair<int, int>>> g(n+1); 
    vector<vector<long long>> reachable(n+1, vector<long long>(4, 0));

    //reachable[i][0] = reachable with 0000
    //reachable[i][1] = reachable with 1111
    //reachable[i][2] = reachable with 0001111
    //reachable[i][3] = reachable with 1*0*
    for(int i = 0; i < n-1; ++i){
        int x, y, c; cin >> x >> y >> c;  
        g[x].push_back({y, c}); 
        g[y].push_back({x, c});
    }

    long long ans = 0;
    function<void(int, int)> dfs = [&](int u, int prev){
        for(auto [v, t] : g[u]){
            if(v == prev) continue; 
            dfs(v, u); 
            if(t == 0){
                reachable[u][0] += 1 + reachable[v][0]; 
                reachable[u][2] += reachable[v][1] + reachable[v][2]; 
            }
            else{
                reachable[u][1] += 1 + reachable[v][1]; 
                reachable[u][3] += reachable[v][0] + reachable[v][3];
            }
        }

        ans += 2LL*reachable[u][0] + 2LL*reachable[u][1] + reachable[u][2] + reachable[u][3]; //valid pairs starting at u going down, some count twice
        for(auto [v, t] : g[u]){
            if(v == prev) continue; 
            if(t == 0){
                //pure 0
                ans +=  (1 + reachable[v][0]) * (reachable[u][0] - (1 + reachable[v][0])); // 0000
                ans += (1 + reachable[v][0]) * (reachable[u][1] + reachable[u][2] - reachable[v][2] - reachable[v][1]); //0001  
            }
            else{
                //pure 1 and 0011
                ans += (1 + reachable[v][1]) * (reachable[u][1] - (1 + reachable[v][1]));
                ans += (reachable[v][0] + reachable[v][3]) * (reachable[u][1] - (1 + reachable[v][1]));
            }
        }
    };

    dfs(1, 1); 
    cout << ans << "\n";



    
    return 0;
}