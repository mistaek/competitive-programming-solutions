/*
949C
AC
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
 
using namespace std; 
int n, m, h; 
vector<int> maintain;
vector<int> processed;
vector<vector<int>> g;
map<int, vector<int>> sccs;
vector<int> sccn; 
int ctr = 0;

stack<int> s;
int numSCC = 0;
vector<int> timer, low; 
void dfs(int i)
{
    timer[i] = ++ctr; 
    s.push(i);
    low[i] = timer[i];
    processed[i] = 1; 
    for(auto v : g[i]){
        if(timer[v] == -1) dfs(v); 
        if(processed[v]) low[i] = min(low[i], low[v]);
    }

    if(low[i] == timer[i]){
        ++numSCC;
        while(1){
            int v = s.top(); s.pop(); processed[v] = 0;
            sccs[numSCC].push_back(v);
            sccn[v] = numSCC;
            if(i == v) break; 
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> h; 
 
    maintain = vector<int>(n+1);
    g = vector<vector<int>>(n+1);
    timer = vector<int>(n+1, -1); 
    low = vector<int>(n+1, 1e9); 
    processed = vector<int>(n+1, 0);
    sccn = vector<int>(n+1, -1);
 
    for(int i = 0; i < n; ++i){
        cin >> maintain[i+1];
    }
 
    if(h == 2){
        // undirected graph
        for(int i = 0; i < m; ++i){
            int c1, c2; cin >> c1 >> c2; 

            g[c1].push_back(c2);
            g[c2].push_back(c1);
        }
        int curind = 1;
        for(int i = 1; i <= n; ++i){
            if(processed[i]) continue; 
            queue<int> bfs; 
            bfs.push(i); 
            while(!bfs.empty()){
                auto v = bfs.front(); bfs.pop();
 
                if(processed[v]) continue; 
                processed[v] = curind; 
                sccs[curind].push_back(v);
                for(auto e : g[v]){
                    if(processed[e] == 0) bfs.push(e);
                }
            }
            ++curind;
        }
    }
 
    else
    {
        for(int i = 0; i < m; ++i){
            int c1, c2; cin >> c1 >> c2; 
            if(maintain[c1] == (maintain[c2] + 1) % h) g[c2].push_back(c1);
            if(maintain[c2] == (maintain[c1] + 1) % h) g[c1].push_back(c2);
        }
    
        for(int i = 1; i <= n; ++i){
            if(timer[i] == -1){
                dfs(i);
            }
        }
    }
    int best = 1e9, besti = 0;
    for(auto [ind, vec] : sccs){
        bool sink = true; 
        for(auto v : vec){
            for(auto e : g[v]){
                if(sccn[e] != sccn[v]){
                    sink = false; 
                    break; 
                }
            }
            if(!sink) break; 
        }
        if(!sink) continue; 
        if(vec.size() < best){
            best = vec.size();
            besti = ind; 
        }
    }

    cout << best << "\n";
    for(int i = 0; i < sccs[besti].size(); ++i){
        if(i) cout << " "; 
        cout << sccs[besti][i];
    }
    cout << "\n";
 
    return 0;
}