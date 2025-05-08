/*
1153D
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<vector<int>> g; 
vector<int> p; 
vector<int> type; 

int num_leaves = 0; 
int solve(int u){
    int delta = (type[u]) ? 1e9 : ((int)g[u].size() - 1); 
    if(g[u].empty()){ return 0;} 


    for(auto v : g[u]){
        if(type[u]) delta = min(delta, solve(v)); 
        else delta += solve(v); 
    }

    //cout << u << " " << delta << "\n";
    return delta; 
}

int main(){
    cin.tie(0); 
    cout.tie(0);
    ios_base::sync_with_stdio(0); 
    int n; cin >> n; 
    g = vector<vector<int>>(n+1); 
    p = type = vector<int>(n+1, 0); 

    for(int i = 1; i <= n; ++i) cin >> type[i]; 
    for(int i = 2; i <= n; ++i){
        cin >> p[i]; 
        g[p[i]].push_back(i); 
    }
    //1 is root
    for(int i = 1; i <=n; ++i){
        if(g[i].empty()) ++num_leaves;
    }
    cout << num_leaves - solve(1) << "\n"; 

    return 0;
}