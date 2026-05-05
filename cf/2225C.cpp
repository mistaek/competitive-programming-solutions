/*
2225C
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> grid(2, vector<int>(n));
        for(int i = 0; i < 2*n; ++i){
            char c; cin >> c;
            grid[i/n][i%n] = (c == 'R');
        }

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            if(grid[0][i] == grid[1][i]) continue;
            else {
                if(i < n-1) {
                    if (grid[0][i] == grid[0][i+1] && grid[1][i] == grid[1][i+1]) {
                        ++i;
                        continue;
                    }
                }
                ++ans;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}