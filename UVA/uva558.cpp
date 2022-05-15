/*
uva 558
ac
*/

#include <cstdio>
#include <vector>

typedef long long lol; 
using namespace std; 

int main(){
    lol c; scanf("%lld", &c); 

    while(c--){
        lol n, m; 
        scanf("%lld %lld", &n, &m);
        
        vector<pair<lol, lol>> adj[n]; 
        vector<lol> dist(n, 1e9);

        for(lol i = 0; i < m; i++){
            lol a, b, p; scanf("%lld %lld %lld", &a, &b, &p); 

            adj[a].push_back({b, p});

        }

        dist[0] = 0;    

        for(lol i = 0; i < n-1; i++){
            for(lol u = 0; u < n; u++){
                for(pair<lol, lol> v : adj[u]){
                    if(dist[v.first] > dist[u] + v.second){
                        dist[v.first] = dist[u] + v.second; 
                    }
                }
            }
        }

        bool yes = false; 

        for(lol u = 0; u < n; u++){
            for(pair<lol, lol> v : adj[u]){
                if(dist[v.first] > dist[u] + v.second){
                    yes = true; 
                }
            }
        }
        if(yes) printf("possible\n"); 
        else printf("not possible\n");
    }
    return 0;
}