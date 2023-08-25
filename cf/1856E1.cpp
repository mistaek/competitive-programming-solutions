/*
1856E1 
*/

#include <iostream>
#include <vector>
using namespace std; 

long long solve(int p, int i, vector<vector<int>> &g){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; 
    vector<vector<int>> g(n+1); 
    for(int i = 1; i <= n; i++){
        int v; cin >> v; 
        g[i].push_back(v); 
        g[v].push_back(i);
    }
    cout << solve(0, 1, g);
    return 0;
}
