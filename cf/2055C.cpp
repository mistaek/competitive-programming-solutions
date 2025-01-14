/*
2055C
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        string path; cin >> path; 
        vector<vector<long long>> grid(n, vector<long long>(m)); 
        long long rs[n] = {}, cs[m] = {}; 
        vector<set<pair<int, int>>> rzs(n), czs(m); 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> grid[i][j]; 
                rs[i] += grid[i][j]; 
                cs[j] += grid[i][j];
            }
        }
        pair<int, int> loc = {0, 0};
        rzs[0].insert(loc); 
        czs[0].insert(loc);
        for(char c: path){
            if(c == 'D'){
                loc.first++; 
                rzs[loc.first].insert(loc); 
                czs[loc.second].insert(loc); 
            }
            else{
                loc.second++; 
                rzs[loc.first].insert(loc); 
                czs[loc.second].insert(loc); 
            }
        }
        //make x 0, unsure why but it seems to work
        queue<pair<int, int>> q; 
        for(int i = 0; i < n; ++i){
            if(rzs[i].size() == 1) q.push({i, 0});
        }
        for(int i = 0; i < m; ++i){
            if(czs[i].size() == 1) q.push({i, 1});
        }
        while(!q.empty()){
            auto [idx, type] = q.front(); 
            q.pop();
            pair<int, int> loc;
            if(type == 0){
                if(rzs[idx].empty()) continue; 
                loc = *rzs[idx].begin(); //should only have 1
                grid[loc.first][loc.second] = -rs[loc.first]; 
            }
            else{
                if(czs[idx].empty()) continue; 
                loc = *czs[idx].begin(); 
                grid[loc.first][loc.second] = -cs[loc.second]; 
            }
            
            rzs[loc.first].erase(loc); 
            czs[loc.second].erase(loc); 
            
            rs[loc.first] += grid[loc.first][loc.second]; 
            cs[loc.second] += grid[loc.first][loc.second]; 
            if(rzs[loc.first].size() == 1){
                q.push({loc.first, 0}); 
            }
            if(czs[loc.second].size() == 1){
                q.push({loc.second, 1});
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j) cout << " "; 
                cout << grid[i][j]; 
            }
            cout << "\n";
        }
    }
    return 0;
}