/*
2053E
AC, editorial
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

vector<vector<int>> g; 
vector<bool> hasLeafChild; 
map<pair<int, int>, int> cnt;  


int main(){
    int t; cin >> t; 
    while(t--){
        // we want: number of leaves * number of nonleaves + number of nonleaves whose parents have a leaf * number of nonleaves in opposite direction who don't have a leaf
    
        long long n; cin >> n; 
        g = vector<vector<int>>(n); 
        hasLeafChild = vector<bool>(n, false); 
        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v; 
            --u, --v; 
            g[u].push_back(v); 
            g[v].push_back(u);
        }
        long long lfcnt = 0, ans = 0; 
        for(int i = 0; i < n; ++i){
            if(g[i].size() == 1){   
                ++lfcnt; 
                hasLeafChild[g[i][0]] = true; 
            }
        }

        ans += lfcnt * (n-lfcnt); 

        long long internalCnt = 0;
        
        for(int i = 0; i < n; ++i){
            if(g[i].size() != 1 && !hasLeafChild[i]){
                ++internalCnt; 
            }
        }

        for(int i = 0; i < n; ++i){
            if(g[i].size()!= 1 && hasLeafChild[i]){
                long long k =0;
                for(auto c : g[i]){
                    if(g[c].size() != 1){
                        ++k; 
                    }
                }
                if(k > 0) ans += internalCnt*(k-1);
            }
        }

        cout << ans << "\n";

        

    }
    return 0;
}