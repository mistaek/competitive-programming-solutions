/*
uva 10449
ac
*/

#include <cstdio>
#include <vector>

using namespace std; 

int main(){
    int n, count= 1; 
    while(scanf("%d", &n) == 1){
        printf("Set #%d\n", count++);
        vector<pair<int, int>> adj[205]; 
        vector<int> dist(205, 1e9);
        int busy[205]; 
        for(int i = 1; i <= n; i++){
            scanf("%d", &busy[i]);
            //printf("%d ", busy[i]); 
        }

        int r; scanf("%d", &r);
        for(int i = 0; i < r; i++){
            int a, b; scanf("%d %d",&a, &b); 

            int cost = busy[b] -busy[a]; 
            //printf("Cost (to be cubed) is %d\n", cost);

            cost = cost * cost * cost; 

            adj[a].push_back({b, cost});
            //printf("Pushed edge %d-%d with cost %d\n", a, b, cost);

        }

        dist[1] = 0;
        for(int i = 1; i <= n-1; i++){
            for(int u = 1; u <= n; u++){
                if(dist[u] == 1e9) continue; 
                for(pair<int, int> v : adj[u]){
                    
                    //printf("%d %d %d\n",u, v.first, v.second);
                    if(dist[v.first] > dist[u] + v.second){
                        dist[v.first] = dist[u] + v.second; 
                        //printf("using edge %d-%d, dist of %d updated to %d\n",u, v.first, v.first, dist[v.first]);

                    } 
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int u = 1; u <= n; u++){
                if(dist[u] == -1e9) continue; 
                if(dist[u] == 1e9){ dist[u] = -1e9; continue;}
                //printf("Dist to %d is %d\n", u, dist[u]);
                for(pair<int, int> v : adj[u]){
                    if(dist[v.first] > dist[u] + v.second){
                        dist[v.first] = -1; 
                        //printf("using edge %d-%d, dist of %d updated to %d\n",u, v.first, v.first, dist[v.first]);

                    } 
                }
            }
        }

        int q; scanf("%d", &q);
        while(q--){
            int v; scanf("%d", &v); 
            if(dist[v] < 3) printf("?\n"); 
            else printf("%d\n", dist[v]);
        }

    }
    
    return 0;
}