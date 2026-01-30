/*
2183D1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> cnt(n, 0), dist(n, -1), p(n, -1);
        vector<vector<int>> depth(n);
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
                    p[c] = top;
                }
            }
        }
        for(int i = 0; i < n; ++i) { cnt[dist[i]]++; depth[dist[i]].push_back(i); }
        cnt[1]++;
        for(int i = 1; i < n; ++i){
            if(dist[i] == n-1) continue;
            if((int)g[i].size() == cnt[dist[i]+1] + 1) cnt[dist[i]+1]++;
        }

        int numRows = *max_element(cnt.begin(), cnt.end());
        cout << numRows << "\n";

        vector<int> row(n, -1);
        vector<vector<int>> rows(numRows);

        row[0] = 0;
        for(int d = 1; d < n; ++d){
            int row1 = 0, row2 = numRows-1;
            for(auto u : depth[d]) {
                if(row1 == row2 && row1 == row[p[u]]){
                    row[u] = row1;
                    for(auto v : depth[d]) {
                        if(row1 != row[p[v]]){
                            swap(row[v], row[u]);
                            break;
                        }
                    }
                }
                else if(row1 == row[p[u]]) row[u] = row2--;
                else row[u] = row1++;
            }
        }

        for(int i = 0; i < n; ++i) rows[row[i]].push_back(i);
        
        for(int i = 0; i < numRows; ++i){
            cout << rows[i].size();
            for(int j = 0; j < (int)rows[i].size(); ++j) {
                cout << " ";
                cout << rows[i][j] + 1;
            }
            cout << "\n";
        }
    }
    return 0;
}