/*
1776F
AC
*/

#include <iostream>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        vector<vector<int>> g(n+1);
        pair<int, int> edges[m];
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            edges[i].first = u, edges[i].second = v;  
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool complete = true; int target = 1; 
        for(int i = 1; i <= n; i++){
            if(g[i].size() != n-1){
                target = i; 
                complete = false; 
                break; 
            }
        }
        if(complete) cout << 3 << "\n"; 
        else cout << 2 << "\n";
        bool completer = false; 
        for(int i = 0; i < m; i++){
            if(i) cout << " ";
            if(edges[i].first != target && edges[i].second != target){
                cout << 1; 
            }
            else{
                if(complete && !completer){
                    cout << 3; 
                    completer = true; 
                }
                else cout << 2;
            }
        }
        cout << "\n";
    }
    return 0;
}
