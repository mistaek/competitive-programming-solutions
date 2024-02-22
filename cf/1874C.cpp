/*
1874C
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std; 
vector<double> dp; 

double p[5000][5000] = {}; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    for(int j = 0; j < 5000; j++){
            p[0][j] = 1.0/(j+1);
    }
    for(int i = 1; i < 5000; i++){
        for(int j = 0; j < 5000; j++){
            if(i >= 2){
                p[i][j] += (double) p[i-2][j] * (i-1)/(i+1+j); 
            }
            if(j > 0){
                p[i][j] += (double) p[i-1][j-1] * j/(i+1 +j);
            }
        }

    }
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        vector<vector<int>> g(n + 1); 
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
        }

        
        dp = vector<double>(n+1, 0);
        dp[n] = 1; 
        for(int i = n-1; i >= 1; i--){
            int sz = g[i].size();
            sort(g[i].begin(), g[i].end(), [](int first, int second){
                return dp[first] > dp[second];
            }); 
            for(int j = 0; j < sz; j++){
                dp[i] += p[j][sz-1-j] * dp[g[i][j]];
            }
            
        }

        cout << std::setprecision(15) << dp[1] <<"\n";
    }
    return 0;
}