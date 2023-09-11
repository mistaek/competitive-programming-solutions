/*
1869A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t; 
    while(t--){
        int n, m; 
        cin >> n >> m; 
        int a[n][m] = {}; 
        int shift = m-1; 
        if(n < m){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    a[i][j] = (j + shift) % m; 
                }
                shift--; 
            }
        }
        else{
            for(int i = 0; i < n- m+1; i++){
                for(int j = 0; j < m; j++){
                    a[i][j] = (j+shift) % m; 
                }
            }
            for(int i = n-m+1; i < n; i++ ){
                for(int j = 0; j < m; j++){
                    a[i][j] = (j + shift) % m; 
                }
                shift--; 
            }
        }
        if(m == 1) cout << 0 << "\n";
        else cout << min(n+1, m) << "\n"; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j) cout << " "; 
                cout << a[i][j];
            }
            cout << "\n"; 
        }
    }
    return 0;
}