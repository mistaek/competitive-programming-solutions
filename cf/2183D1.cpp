/*
2183D1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> cnt(n, 0), dist(n, -1);
        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v;
            --u; --v;
            g[u].push_back(v); g[v].push_back(u);
        }

        dist[0] = 0;
        queue<int> bfs;
        bfs.push(0);
        while(!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            for(auto c : g[top]){
                if(dist[c] == -1) {
                    dist[c] = dist[top] + 1;
                    bfs.push(c);
                }
            }
        }
        for(int i = 0; i < n; ++i) cnt[dist[i]]++;
        cnt[1]++;
        for(int i = 1; i < n; ++i){
            if(dist[i] == n-1) continue;
            if((int)g[i].size() == cnt[dist[i]+1] + 1) cnt[dist[i]+1]++;
        }

        cout << *max_element(cnt.begin(), cnt.end()) << "\n";
    }
    return 0;
}