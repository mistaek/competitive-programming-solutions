/*
1833G
AC
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

map<pair<int, int>, int> el;
int cut; 
void DFS(int u, vector<vector<int>> &g, vector<vector<int>> &c, vector<vector<int>> &d, vector<int> &p, int depth=0){
    d[depth].push_back(u);
    for(int v : g[u]){
        if(v == p[u]) continue; 
        c[u].push_back(v);
        p[v] = u; 
        DFS(v, g, c, d, p, depth+1);
    }
}

bool createBranch(int v, vector<int> &p, vector<vector<int>> &c, vector<int> &u, vector<int> &used){
    if(u[p[v]]) return false; 
    for(int child : c[p[v]]){
        if(child == v) continue; 
        if(!u[child]){
            u[v] = 1; 
            u[child]= 1; 
            u[p[v]] = 1; 
            used[el[{min(v, p[v]), max(v, p[v])}]] = 1;
            used[el[{min(p[v], child), max(p[v], child)}]] = 1;
            //cout << "branch made: child " << v << " " << child << " " << p[v] << "\n";
            cut += 2; 
            return true; 
        }
    }
    if(u[p[p[v]]]){
        return false;     
    }
    u[p[p[v]]] = 1; 
    u[v] = 1; 
    u[p[v]] = 1;
    used[el[{min(v, p[v]), max(v, p[v])}]] = 1; 
    used[el[{min(p[v], p[p[v]]), max(p[v],p[p[v]])}]] = 1; 
    //cout << "branch made: grandparent " << v << " " << p[v] << " " << p[p[v]] << "\n";
    cut += 2; 
    return true; 
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    while(t--){
        el.clear(); 
        int n; cin >> n; 
        cut = 0;
        vector<vector<int>> g(n+1), d(n+1), c(n+1); 
        vector<int> p(n+1, 0), u(n+1, 0), used(n+1, 0);
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u);
            el[{min(u, v), max(u,v)}] = i+1; 
        }

        if(n % 3){
            cout << -1 << "\n";
            continue; 
        }
        
        DFS(1,g,c,d,p); // O(n)
        bool ans = true; 
        //below should be O(2nlogn) or smth
        for(int i = n-1; i >= 0; i--){
            for(int v : d[i]){
                if(u[v]) continue; 
                if(!createBranch(v, p, c, u, used)){
                    ans = false; 
                    //cout << "break on vertex " << v << "\n";
                    break; 
                }
            }
            if(!ans) break; 
        }
        if(!ans){
            cout << "-1\n";
        }
        else{
            cout << n - 1 -cut << "\n"; 
            bool printed = false; 
            for(int i = 1; i< n; i++){
                
                if(!used[i]){
                    if(printed) cout << " "; 
                    cout << i;
                    printed =true; 
                }
            }
            cout << "\n";
        }
        //cout << "\n";
    }
    return 0;
}