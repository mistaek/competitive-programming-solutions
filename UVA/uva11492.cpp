/*
uva 11492
wip
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(){
    int m; 
    while(scanf("%d", &m), m){
        map<string, int> graph; 
        string s, e; cin >> s >> e; 
        graph[s] = 0; graph[e] = 1; int counter = 2; 

        vector<pair<int, pair<int, char>>> adj[5000];
        for(int i = 0; i < m; i++){
            string a, b, p; cin >> a >> b >> p; 
            if(graph.count(a) == 0) graph[a] = counter++;
            if(graph.count(b) == 0) graph[b] = counter++; 

            adj[graph[a]].push_back({graph[b], {(int) p.length(), p[0]}}); 
            adj[graph[b]].push_back({graph[a], {(int) p.length(), p[0]}});
        }
        
        int dist[5000]; for(int i = 0; i < 5000; i++) dist[i] = 1e9;

        dist[graph[s]] = 0; 

        priority_queue<pair<int, pair<int, char>>> pq; 

        pq.push({0,{0, ' '}}); 


        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second.first;
            char last = pq.top().second.second;
            pq.pop();
            if(d > dist[u]) continue; 

            for(pair<int,pair<int, char>> v : adj[u]){
                if(v.second.second != last){
                    if(dist[v.first] > dist[u] + v.second.first){
                        dist[v.first] = dist[u] + v.second.first; 
                        pq.push({dist[v.first], {v.first, v.second.second}});
                    }
                }
            }  
        }
        if(dist[graph[e]] == 1e9) printf("impossivel\n");
        else printf("%d\n", dist[graph[e]]);


    }
    return 0;
}