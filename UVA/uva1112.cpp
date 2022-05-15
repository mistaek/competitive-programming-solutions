/*
uva1112
AC - watch out for redeclared variables!
*/

#include <cstdio>
#include <vector> 
#include <cstring>
#include <queue>
#include <functional> 
#include <algorithm>

using namespace std; 

int main(){
    int test; scanf("%d", &test);
    while(test--){
        int n, e, t; scanf("%d %d %d", &n, &e, &t);
        int m; scanf("%d", &m); 
        vector<pair<int,int>> adj[n+1]; 
        for(int i = 0; i < m;i++){
            int a, b, c; scanf("%d %d %d", &a, &b, &c); 
            adj[a].push_back({b, c});
        }
        int ans = 0; 
        for(int i = 1 ; i <= n; i++){
            int dist[n+1] = {};
            for(int j = 0; j <= n; j++) dist[j] = 1e9;
            //printf("%d\n", dist[e]); 
            dist[i] = 0; 
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({0, i});

            while(!pq.empty()){
                int d = pq.top().first, v = pq.top().second; pq.pop();

                if(d > dist[v]) continue; 
                for(pair<int, int> u : adj[v]){
                    if(dist[v] + u.second < dist[u.first]){
                        dist[u.first] = dist[v] + u.second; 
                        pq.push({dist[u.first], u.first});
                    }
                }
            }
            //printf("From Vertex %d, distance to end %d is %d\n", i, e, dist[e]);
            if(dist[e] <= t) ans++;
        }

        printf("%d\n", ans);
        if(test) printf("\n");
        
    }
    return 0;
}