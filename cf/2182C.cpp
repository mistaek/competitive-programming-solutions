/*
2182C
*/

#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> abc(3, vector<int>(n));
        
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < n; ++j) cin >> abc[i][j];
        }

        long long ans1 = 0, ans2 = 0;
        for(int j = 0; j < n; ++j){
            ++ans2;
            for(int i = 0; i < n; ++i){
                if(abc[1][i] >= abc[2][(i+j) % n]) {
                    --ans2; break;
                }
            }
        }

        for(int j = 0; j < n; ++j){
            ++ans1;
            for(int i = 0; i < n; ++i){
                if(abc[0][i] >= abc[1][(i+j) % n]) {
                    --ans1; break;
                }
            }
        }
        cout << ans1 *ans2*n << "\n";
        
    }
    return 0;
}