/*
2102C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

int main(){
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(0);  
    
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 

        vector<vector<int>> ans(n, vector<int>(n, 0)); 
        int i = (n-1)/2, j = (n-1)/2; 

        ans[i][j] = 0;
        int curlen = 1, curwidth = 1, curdir = 0;
        pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int total = 1; 
        while(total < n * n){
            int dim = (curdir % 2) ? curwidth : curlen; 
            //cout << "DEBUG: " << curdir << " " << dim << "\n";
            for(int k = 0; k < dim; ++k){
                i += dir[curdir].first, j += dir[curdir].second; 
                if(i < 0 || i >= n || j < 0 || j >= n) break; 
                ans[i][j] = total++; 
            }
            if(i < 0 || i >= n || j < 0 || j >= n) break; 

            if(curdir %2) curwidth++; 
            else curlen++; 
            curdir++; 
            curdir %= 4; 
        }
        

        for(i = 0; i < n; ++i){
            for( j = 0; j < n; ++j){
                if(j) cout << " "; 
                cout << ans[i][j]; 
            }
            cout << "\n";
        }
    }
    return 0;
}