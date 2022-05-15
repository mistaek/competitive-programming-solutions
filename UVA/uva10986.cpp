/*
uva 10986
wip
*/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std; 

int main(){
    int tc; scanf("%d", &tc); 
    for(int TC = 1; TC <= tc; TC++){
       int n, m, s, t;  scanf("%d %d %d %d", &n, &m, &s, &t);
       vector<pair<int, int>> adj[n]; 
       for(int i = 0; i < m; i++){
            int a, b, c; 
            scanf("%d %d %d", &a, &b, &c); 
            adj[a].push_back({b, c}); 
            adj[b].push_back({a, c});
       }
       vector<int> dist(n, 1e9); dist[s] =0;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, s});

       while(!pq.empty()){
            int d = pq.top().first, v = pq.top().second; 
            pq.pop();   

			if(d > dist[v]) continue;

			for(pair<int, int> u : adj[v]){
				if(u.second + dist[v] < dist[u.first]){

				 	dist[u.first] = u.second + dist[v]; 
					pq.push({dist[u.first], u.first});
				}

			}
       }
	   printf("Case #%d: ", TC);
	   if(dist[t]!= 1e9) printf("%d\n", dist[t]); 
	   else printf("unreachable\n");
    }
    return 0;
}