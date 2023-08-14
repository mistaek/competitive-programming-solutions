/*
1648A
AC - watch bounds!! cringe!!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m; cin >> n >> m;

    vector<vector<int>> cr(100000), cc(100000); //a bit much?

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c; cin >> c; 
            cr[--c].push_back(i); cc[c].push_back(j);
        }
    }

    for(int i = 0; i < 100000; i++){
        sort(cr[i].begin(), cr[i].end()); 
        sort(cc[i].begin(), cc[i].end());
    }

    long long ans = 0; 
   
    for(int i = 0; i < 100000; i++){
        long long gap = 0;
        for(int j = 1; j < cr[i].size(); j++){
            if(cr[i][j] != cr[i][j-1]){
                gap += j * (cr[i][j] - cr[i][j-1]);
                
            }
            ans += gap; 
        }
        gap = 0;
        for(int j = 1; j < cc[i].size(); j++){
            if(cc[i][j] != cc[i][j-1]){
                gap += j * (cc[i][j] - cc[i][j-1]);
            }
            ans += gap; 
        }
    }

    cout << ans << "\n"; 

    return 0;
}