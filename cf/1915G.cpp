/*
1915G
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<pair<long long, long long>>> adjList(n+1); 
        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w}); 
            adjList[v].push_back({u, w});
        }
        vector<long long> si(n+1);
        for(int i = 1; i <= n; i++){
            cin >> si[i];
        }

        vector<vector<long long>> d(n+1, vector<long long>(1001, 1e18)); //shortest distance arriving at idx with fastest bike bike [idx][bike]
        d[1][si[1]] = 0;
        priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq; //dist, idx, bike 
        pq.push({0, {1, si[1]}});
        while(!pq.empty()){
            long long dist = pq.top().first, idx= pq.top().second.first, bike = pq.top().second.second;
            pq.pop();
            if(dist > d[idx][bike]) continue; 
            d[idx][bike] = dist; //for safety, shouldn't matter?
            
            long long nb = min(bike, si[idx]); //take fastest bike as new bike
            for(auto e : adjList[idx]){
                if(d[idx][bike] + (nb * e.second) < d[e.first][nb]){
                    d[e.first][nb] = d[idx][bike] + (nb * e.second);
                    pq.push({d[e.first][nb], {e.first, nb}});
                }
            }
        }
        long long ans = 1e18; 
        for(int i = 1; i <= 1000; i++) ans = min(ans, d[n][i]);
        cout << ans << "\n";
    }
    return 0;
}