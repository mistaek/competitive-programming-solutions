/*
uva 10801
ac POG
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <sstream> 
#include <algorithm>


using namespace std; 
int main(){
    int n, k; 
    while(scanf("%d %d\n", &n, &k) != EOF){
        int times[n]; for(int i = 0; i < n; i++) scanf("%d", &times[i]);
        scanf("\n"); 

        vector<int> adj[100][5]; 
        int dist[100][5]; for(int i = 0; i < 100; i++) for(int j = 0; j < 5; j++) dist[i][j] = 1e9;
        priority_queue<pair<int, pair<int, int>>> pq; 
        stringstream ss; string line;  

        for(int i = 0; i < n; i++){
            ss.clear(); getline(cin, line); 

            ss << line; 
        
            int u, v; ss >> u; 
            if(u == 0){ pq.push({0,{u, i}});dist[0][i] = 0; }

            while( ss >> v){
                adj[u][i].push_back({v}); 
                adj[v][i].push_back({u}); 

                u = v; 
            }
        }

        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second.first, ele = pq.top().second.second; 
            pq.pop(); 

            if(d > dist[u][ele]) continue; 

            for(int v : adj[u][ele]){
                int nxt = abs(times[ele] * (v - u));
                if(dist[v][ele] > nxt + dist[u][ele]){ dist[v][ele] = nxt + dist[u][ele]; pq.push({nxt + dist[u][ele], {v, ele}});}
            }

            for(int i = 0; i < 5; i++){
                if(i != ele){
                    if(dist[u][i] > 60 + dist[u][ele]){dist[u][i] = 60 + dist[u][ele];  pq.push({60 + dist[u][ele], {u, i}});}
                }
            }
            
        }
        int ans = 1e9; 
        for(int i = 0; i < 5; i++){
            ans = min(ans, dist[k][i]);
        }

        if(ans == 1e9) printf("IMPOSSIBLE\n"); 
        else printf("%d\n", ans);


    }
    
    return 0;
}