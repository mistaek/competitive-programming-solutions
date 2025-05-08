/*
1152E
AC, hierholzer
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std; 


int main(){
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(false); 
    int n; cin >> n; 
    vector<int> b(n-1), c(n-1); 
    bool possible = true; 
    for(int i = 0; i < n-1; ++i){
        cin >> b[i]; 
    }
    for(int i = 0; i < n-1; ++i){
        cin >> c[i]; 
        if(c[i] < b[i]){
            possible = false; 
        }
    }

    if(!possible){
        cout << -1 << "\n"; 
        return 0;
    }

    map<int, vector<pair<int, int>>> g; 
    map<int, int> d; //degree, self loops are 2
    vector<bool> seen(n-1, false); 
    for(int i = 0; i < n-1; ++i){
        g[b[i]].push_back({c[i], i}); 
        g[c[i]].push_back({b[i], i}); 
        ++d[b[i]]; 
        ++d[c[i]]; 
    }

    vector<int> ans; 
    function<void(int)> dfs = [&](int u){
        while(!g[u].empty()){
            auto [v, idx] = g[u].back(); 
            g[u].pop_back(); 
            if(seen[idx]) continue; 
            seen[idx] = true; 
            dfs(v); 
        }
        ans.push_back(u); 
    };
    vector<int> odd; 
    for(auto const& [v, dv] : d){
        if(dv % 2){
            odd.push_back(v); 
        }
    }

    if(odd.size() > 2){
        cout << -1 << "\n"; 
        return 0;
    }
    if(odd.empty()) dfs(b[0]); 
    else dfs(odd[0]); 
    
    if(ans.size() != n){
        cout << -1 <<"\n"; 
        return 0; 
    }
    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << " "; 
        cout << ans[i]; 
    }
    cout << "\n";

    return 0;
}