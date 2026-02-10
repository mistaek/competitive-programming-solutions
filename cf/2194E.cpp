/*
2194A
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
    
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<long long>> g(n, vector<long long>(m)), fwd(n, vector<long long>(m)), bwd(n, vector<long long>(m));
        vector<vector<long long>> hori(n, vector<long long>(m)), vert(n, vector<long long>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) cin >> g[i][j];
        }
        long long ans = 1e18;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) fwd[i][j] = g[i][j];
                else if (i == 0) fwd[i][j] = fwd[i][j-1] + g[i][j];
                else if (j == 0) fwd[i][j] = fwd[i-1][j] + g[i][j];
                else fwd[i][j] = max(fwd[i-1][j], fwd[i][j-1]) + g[i][j];
            }
        }
    
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                if(i == n-1 && j == m-1) bwd[i][j] = g[i][j];
                else if (i == n-1) bwd[i][j] = bwd[i][j+1] + g[i][j];
                else if (j == m-1) bwd[i][j] = bwd[i+1][j] + g[i][j];
                else bwd[i][j] = max(bwd[i+1][j], bwd[i][j+1]) + g[i][j];
            }
        }
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                hori[i][j] = fwd[i][j] + bwd[i][j] - g[i][j];
                vert[i][j] = fwd[i][j] + bwd[i][j] - g[i][j];
                if(i < n-1) vert[i][j] = max(vert[i+1][j], vert[i][j]);
                if(j < m-1) hori[i][j] = max(hori[i][j+1], hori[i][j]);
            }
        }
        int ci = n-1, cj = m-1;
        long long best = g[0][0];
        vector<pair<int, int>> bpath;
        while(ci != 0 || cj != 0) {
            best += g[ci][cj];
            bpath.push_back({ci, cj});
            if(ci == 0) --cj;
            else if(cj == 0) --ci;
            else {
                if(fwd[ci-1][cj] + g[ci][cj] == fwd[ci][cj]) {
                    --ci;
                }
                else {
                    --cj;
                }
            }
        }
        // try flip the two corners
        ans = min(best - 2 * g[0][0], best - 2*g[n-1][m-1]);

        // (m+n) * (m + n) TOO SLOW
        for (auto [i, j] : bpath){
            // first entry
            if (i == n-1 && j == m-1) continue;
            long long localans = best - 2*g[i][j];
            if (i > 0 && j < m-1) {
                localans = max(localans, hori[i-1][j+1]);
            }
            if (j > 0 && i < n-1) {
                localans = max(localans, vert[i+1][j-1]);
            }
            ans = min(ans, localans);
        }
    
        cout << min(ans, fwd[n-1][m-1]) << "\n";
    }
    return 0;
}