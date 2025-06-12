/*
1158C
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n+2);
        vector<vector<int>> g(n+2); 
        for(int i = 1; i <= n; ++i){
            cin >> a[i]; 
        } 
        
        for(int i = n; i >= 1; --i){
            if(a[i] == -1) a[i] = i+1; 
        }

        int total = 0, previ = 0, val = n;
        vector<int> ans(n+1); 
        bool pos = true; 
        for(int i = 1; i <= n; ++i){
            g[a[i]].push_back(i);
            if(a[i] == n+1){
                // run bfs from this spot
                queue<int> bfs; 
                bfs.push(i); 
                while(!bfs.empty()){
                    auto idx = bfs.front(); 
                    bfs.pop();
                    ans[idx] = val--;
                    total++; 
                    for(auto u : g[idx]) bfs.push(u);
                }
                if(total != i - previ){
                    pos = false; break; 
                }
                total = 0; 
                previ = i;
            }
        }
        if(pos){
            int next = n+1;
            vector<int> nxt(n+1, n+1);
            for(int i = n; i >= 1; --i){
                next = i+1; 
                while(next != n+1){
                    if(ans[next] > ans[i]) break; 
                    next = nxt[next];
                }
                nxt[i] = next; 
                if(nxt[i] != a[i]){
                    pos = false; 
                    break;
                }
            }
        }
        if(pos){
            for(int i = 1; i <= n; ++i) cout << ans[i] << " "; 
            cout << "\n";
        }
        
        if(!pos) cout << "-1\n";
    }
    return 0;
}