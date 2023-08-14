/*
UVa 924
Ray
AC
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
//bfs distance tracking

using namespace std; 
int main(){
    int e; scanf("%d\n", &e);
    vector<int> adjl[e];
    for(int i = 0; i < e; i++){
        int f; scanf("%d", &f); 
        while(f--){ int num; scanf("%d", &num); adjl[i].push_back(num);}
        
    }

    int t; scanf("%d\n", &t);
    while(t--){
        int source; scanf("%d", &source); 
        vector<int> dist(e, -1), boom(e, 0);
        queue<int> q;  
        dist[source] = 0; q.push(source); boom[0]++; 
        int bigboom = 0, bigday = 0; 
        while(!q.empty()){
            int v = q.front(); q.pop(); 
            for(int u : adjl[v]){
                if(dist[u] == -1){
                    dist[u] = dist[v]+1; 
                    boom[dist[u]]++;
                    if(boom[dist[u]] > bigboom){
                        bigday = dist[u]; 
                        bigboom = boom[dist[u]];
                    }
                    q.push(u);
                }
            }
        }
        if(bigday == 0) printf("%d\n", 0); 
        else printf("%d %d\n", bigboom, bigday);

    }
    return 0;
}