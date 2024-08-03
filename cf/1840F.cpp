/*
1840F
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int dist(pair<int, int> a, pair<int, int> b){
    return a.first - b.first + a.second - b.second; 
}
int main(){
    int T; cin >> T; 
    while(T--){
        int n, m; cin >> n >> m; 
        vector<vector<int>> g(n+1,vector<int>(m+1, 0));
        vector<vector<pair<int, int>>> closest(n+1, vector<pair<int, int>>(m+1, {0, 0}));
        int r; cin >> r; 
        vector<pair<int, pair<int, int>>> shots(r); 
        for(int i = 0; i < r; i++){
            cin >> shots[i].first >> shots[i].second.first >> shots[i].second.second; 
        }

        g[0][0] = 1; 
        sort(shots.begin(), shots.end());
        int curt = 0; 
        long long ans = -1; 
        for(int i = 0; i < r; i++){
            //update grid on/off
            int diff = shots[i].first - curt; 
            //upd on/off
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= m; j++){
                    int xd = i - closest[i][j].first, yd = j - closest[i][j].second; 
                    if(xd + yd <= diff) g[i][j] = 1; 
                }
            }
            if(ans == -1 && g[n][m]){
                ans = n - closest[n][m].first + m - closest[n][m].second + curt;
            }
            if(shots[i].second.first == 1){
                for(int j = 0; j <= m; j++){
                    g[shots[i].second.second][j] = 0; 
                }
            }
            else{
                for(int i = 0; i <= n; i++){
                    g[i][shots[i].second.second] = 0; 
                }
            }

            if(g[n][m] == 0 && ans == shots[i].first) ans = -1; 

            //upd closest
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= m; j++){
                    if(g[i][j]) closest[i][j] = {i, j};
                    else closest[i][j] = {-1e5, -1e5};
                    if(i && dist({i, j}, closest[i-1][j]) < dist({i, j}, closest[i][j])) closest[i][j] = closest[i-1][j];
                    if(j && dist({i, j}, closest[i][j-1]) < dist({i, j}, closest[i][j])) closest[i][j] = closest[i][j-1];
                }
            }
            curt = shots[i].first; 
        }
        if(ans == -1 && closest[n][m].first != -1e5) ans = dist({n, m}, closest[n][m] ) + curt; 
        cout << ans << "\n";

    }
    return 0;
}