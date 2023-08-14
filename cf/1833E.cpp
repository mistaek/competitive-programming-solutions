/*
1833E
AC
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<vector<int>> g(n);
        int vis[n] = {};
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            a--; 
            g[i].push_back(a);
            g[a].push_back(i);
        }

        int c=0, cc = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                cc++;
                queue<pair<int, int>> bfs; 
                bool cycle = 0;
                bfs.push({i, -1}); 
                while(!bfs.empty()){
                    int u; 
                    u = bfs.front().first;
                    int prev = bfs.front().second;
                    bfs.pop(); 
                    vis[u] = 1; 

                    for(int v : g[u]){
                        if(v != prev && vis[v]){
                            cycle = true; 
                            break;
                        }
                        else if(!vis[v]){
                            bfs.push({v, u});
                        }
                    }
                    
                }
                if(cycle) c++;
            }
        }
        //cout << c << "\n";
        cout << min(c+1, cc) << " " << cc << "\n";
    }
    return 0;
}