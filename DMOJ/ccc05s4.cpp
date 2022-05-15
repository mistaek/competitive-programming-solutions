/*
ccc05s4
ac - simple bfs
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
// is the graph acyclic?
using namespace std;

int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        int n; scanf("%d", &n);
        int oldt = n*10, newt = 1e9;
        string names[n]; 
        for(int i = 0; i < n; i++) cin>> names[i];
        int nc = 0;
        map<string, int> graph;
        vector<int> adjl[n];
        for(int i = 0; i<n; i++){
            if(graph.count(names[i]) == 0) graph[names[i]] = nc++;
            if(i){adjl[graph[names[i]]].push_back(graph[names[i-1]]); adjl[graph[names[i-1]]].push_back(graph[names[i]]);}
        }
        int dist[n]; for(int i = 0; i < n; i++) dist[i] = -1; 
        dist[graph[names[n-1]]] = 0;
        queue<int> bfs; 
        bfs.push(graph[names[n-1]]);
        while(!bfs.empty()){
            int u = bfs.front(); bfs.pop(); 
            for(int v : adjl[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u]+1; 
                    bfs.push(v);
                }
            }
        }
        int maxd = 0;
        for(int i = 0; i < n; i++) maxd = max(maxd, dist[i]);
        newt = 20*maxd;
        printf("%d\n", oldt - newt);
    }
    return 0;
}