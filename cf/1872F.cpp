/*
1872F
AC
*/

#include <iostream>
#include <vector>
using namespace std; 

void exploreComponent(int v, vector<int> &sc, vector<int> &p, vector<int> &vis, vector<int> &val, vector<int>&ans){
    int cycle = 0; 
    vector<int> pb; int lowest = -1; 
    int ctr = 0; 
    while(p[v] == 0){
        vis[v] = 1; 
        pb.push_back(v); 
        if(lowest < 0 || val[v] < val[pb[lowest]]) lowest = ctr; 
        ctr++; 
        if(p[sc[v]]) p[sc[v]]--; 
        if(p[sc[v]] == 0){
            if(vis[sc[v]]){
                cycle = 1; 
                break; 
            }
            else{
                v = sc[v];
            }
        }
        else break; 
    }

    for(int i = 0; i < pb.size(); i++){
        int ind = i + (cycle * (lowest + 1));  
        ans.push_back(pb[ind % pb.size()]); 
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> sc(n+1, 0), p(n+1, 0), val(n+1, 0); 
        for(int i = 1; i <= n; i ++){
            cin >> sc[i]; 
            p[sc[i]]++;  
        }
        for(int i = 1; i <= n; i++){
            cin >> val[i]; 
        }
        vector<int> vis(n+1, 0);
        vector<int> ans; 
        for(int i = 1; i <= n; i++){
            if(p[i] == 0 && !vis[i]){
                exploreComponent(i, sc, p, vis, val, ans);
            }
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                p[i]--; 
                exploreComponent(i, sc, p, vis, val, ans);
            }
        }

        for(int i = 0; i < ans.size(); i++){
            if(i) cout << " ";
            cout << ans[i]; 
        }
        cout << "\n";

    }
    return 0;
}