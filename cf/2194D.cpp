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
        int sum = 0;
        vector<vector<int>> g(n, vector<int>(m));
        vector<vector<int>> pref(n, vector<int>(m+1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> g[i][j];
                sum += g[i][j];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = m-1; j >= 0; --j) {
                pref[i][j] += pref[i][j+1];
                pref[i][j] += g[i][j];
            }
        }
        cout << 1LL * (sum/2) * (sum - (sum/2)) << "\n";
        int i = 0, j = 0, curs = 0;
        while(i < n || j < m) {
            if(i == n) {
                ++j; cout << 'R';
                continue;
            }
            if(j == m) {
                ++i; cout << 'D';
                continue;
            }

            if(curs + pref[i][j] <= sum/2) {
                curs += pref[i][j];
                ++i;
                cout << 'D';
            }
            else {
                ++j;
                cout << 'R';
            }
        }
        cout << "\n";
    }
    return 0;
}