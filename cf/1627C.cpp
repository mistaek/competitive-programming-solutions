/*
1627C
AC
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<vector<int>> adj(n+1); 
        vector<pair<int, int>> el; 
        for(int i = 1; i < n; i++){
            int u, v; cin >> u >> v; 
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            el.emplace_back(make_pair(u, v)); 
        }
        int last, cur = 0; 
        for(int i = 1; i <=n; i++){
            if(adj[i].size() == 1){
                cur = i;
                last = i; 
                break; 
            }
        }
        int turn = 0;
        map<pair<int, int>, int> ans; 
        while(cur != -1){
            int temp = cur; 
            if(adj[cur].size() > 2){ 
                cur = -1; 
                break;
            }
            for(int i = 0; i < adj[cur].size(); i++){
                if(adj[cur][i] != last){
                    cur = adj[cur][i]; 
                    ans[make_pair(temp, cur)] = 2 + turn; 
                    ans[make_pair(cur, temp)] = 2+turn; 
                    turn = 1 - turn; 
                    break;
                }
            }
            last = temp; 
            if(last == cur) break; 
        }
        
        if(cur == -1){
            cout << cur << "\n";
            continue; 
        }
        for(int i = 0; i < n-1; i++){
            cout << ((i) ? " " : "") << ans[el[i]];
        }
        cout << "\n";
    }
    
}
