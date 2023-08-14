/*
1775D
AC
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main(){
    int n; cin >> n; 
    vector<vector<pair<int, int>>> g(300000);
    vector<vector<int>> f(300000);
    vector<int> a(n);

    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        int init = a[i]; 
        for(int j = 2; j * j <= init; j++){
            if(init % j) continue; 
            f[i].push_back(j); 
            while(init % j == 0) init/=j; 
        }

        if(init != 1) f[i].push_back(init);
        for(auto fc : f[i]){
            for(auto fc2 : f[i]){
                if(fc != fc2) {
                    //cout << "edge " << fc << " " << fc2 << " " << a[i] << "\n";
                    g[fc2].push_back({fc, i+1});
                    g[fc].push_back({fc2, i+1});
                }
            }
        }
    }


    int s, t; cin >> s >> t; 
    if(s == t){
        cout << 1 << "\n" << s << "\n"; 
        return 0;
    }
    s--; t--; 
    pair<int, pair<int, int>> vis[300000] = {}; 

    queue<pair<int, int>> bfs;
    for(auto fc : f[s]){
        bfs.push({fc, 0});
        vis[fc] = {s+1, {0, 0}}; 
    }
    while(!bfs.empty()){
        pair<int, int> u = bfs.front(); 
        bfs.pop();
        for(auto v : g[u.first]){
            if(!vis[v.first].first){
                //cout << "visiting " << v.first << " from " << u.first << "\n";
                vis[v.first] = {v.second, {u.second+1, u.first}}; 
                bfs.push({v.first, u.second+1});
            }
        }
    }
    int mind = -1, start = -1; 
    for(auto fc : f[t]){
        if(vis[fc].first){
            if(mind == -1 || vis[fc].second.first < mind){
                start = fc; 
                mind = vis[fc].second.first; 
            }
        }
    }

    if(mind == -1){
        cout << mind << "\n"; 

    }
    else{
        
        vector<int> path; 
        if(t+1 != vis[start].first){
            path.push_back(t+1);
        }
        while(start){
            path.push_back(vis[start].first); 
            start = vis[start].second.second;
        }
        cout << path.size() << "\n"; 
        for(auto it = path.rbegin(); it != path.rend(); it++){
            cout << *it << " ";
        }
        cout << "\n";
    }

    
    return 0;
}