/*
1005F
AC
*/
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std; 

vector<vector<pair<int, int>>> g; 
vector<vector<int>> options; 
vector<int> d; 
vector<vector<bool>> out; 
int k, total = 0;
int n, m;
void solve(vector<bool>& ans, int i){
    if(total >= k) return; 
    if(i == n+1){
        ++total; 
        out.push_back(ans); //need to store? could maybe compute online but seems annoying
        return; 
    }
    if(options[i].size() == 0) solve(ans, i+1); //should not happen
    for(auto e: options[i]){
        ans[e] = true; 
        solve(ans, i+1);
        ans[e] = false; 
    }
}  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    g = vector<vector<pair<int, int>>>(n+1);
    options = vector<vector<int>>(n+1);
    d = vector<int>(n+1, -1);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b; 
        g[a].push_back({b, i}); 
        g[b].push_back({a, i});
    }

    queue<int> q; 
    d[1] = 0;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        for(auto [v, i] : g[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1; 
                q.push(v);
            }
            if(d[v] == d[u] + 1){
                options[v].push_back(i);
            }
        }
    }

    vector<bool> ans(m, false); 
    solve(ans, 2);
    cout << total << "\n";
    for(auto& v : out){
        for(auto b : v) cout << (b ? 1 : 0); 
        cout << "\n";
    }
    return 0;
}