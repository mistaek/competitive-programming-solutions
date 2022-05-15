/*
uva 929
AC
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std; 

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, m; scanf("%d %d", &n, &m);
        int cost[n][m], dist[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &cost[i][j]);
                dist[i][j] = 1e9;
            }
        }
         dist[0][0] = cost[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
        pq.push({cost[0][0], {0, 0}});
        while(!pq.empty()){
            int d = pq.top().first, x = pq.top().second.first, y = pq.top().second.second; 
            pq.pop();

            if(d > dist[x][y]) continue; 
            for(int i = 0; i < 4; i++){
                if(x+dx[i] >= n || x + dx[i] < 0 || y + dy[i] >= m || y + dy[i] < 0) continue;

                if(dist[x][y] + cost[x + dx[i]][y + dy[i]] < dist[x+dx[i]][y + dy[i]]){
                    dist[x+dx[i]][y + dy[i]] = dist[x][y] + cost[x + dx[i]][y + dy[i]];
                    pq.push({dist[x+dx[i]][y + dy[i]], {x+dx[i],y + dy[i]}});
                }
            }

        }
        printf("%d\n", dist[n-1][m-1]);
    }
    return 0;
}