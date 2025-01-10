/*
1016D
*/

#include <iostream>

using namespace std; 

int main(){
    int n, m; cin >> n >> m; 
    int r[n], c[m]; 
    for(int i = 0; i < n; ++i) cin >> r[i]; 
    for(int i = 0; i < m; ++i) cin >> c[i]; 
    int ans[n][m] = {};
    int rc = 0, cc = 0;
    bool pos = true; 
    for(int i = 0; i < n-1; ++i){
       
        ans[i][m-1] = r[i]; 
        cc ^= r[i]; 
    }

    for(int j = 0; j < m-1; ++j){ 
        ans[n-1][j] = c[j];
        rc ^= ans[n-1][j];
    }

    if((rc ^ r[n-1]) == (cc ^ c[m-1])){
        ans[n-1][m-1] = rc^r[n-1]; 
    }
    else{
        pos = false; 
    }

    if(pos){
        cout << "YES\n"; 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j) cout << " "; 
                cout << ans[i][j]; 
            }
            cout << "\n"; 
        }
    }
    else cout << "NO\n";
    return 0;
}