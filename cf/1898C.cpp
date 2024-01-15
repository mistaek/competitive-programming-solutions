/*
1898C
ac, got completely lost during impls
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int e = n+m-2; 
        if(k < e){
            cout << "NO\n";
            continue; 
        }
        if((k-e) % 2){
            cout << "NO\n"; 
        }
        else{
            cout << "YES\n";
            int hori[n][m-1] = {}, vert[n-1][m] = {};
            hori[n-1][0] = (n-1)%2; 

            for(int i = 1; i < m-1; i++){
                hori[0][i] = 1-hori[0][i-1]; 
                hori[n-1][i] = 1-hori[n-1][i-1]; 
            }
            vert[0][0] = 1, vert[0][1] = 1, vert[1][0] = 1; 
            vert[0][m-1] = 1-hori[0][m-2];
            vert[1][m-1] = 1-vert[0][m-1];

            for(int i = 2; i < n-1; i++){
                vert[i][0] = 1-vert[i-1][0]; 
                vert[i][m-1] = 1-vert[i-1][m-1];  
            } 

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m-1; j++){
                    if(j) cout << " "; 
                    cout << (hori[i][j] ? "R" : "B"); 
                }
                cout << "\n";
            }

            for(int i = 0; i < n-1; i++){
                for(int j = 0; j < m; j++){
                    if(j) cout << " "; 
                    cout << (vert[i][j] ? "R" : "B"); 
                }
                cout << "\n";
            }

            

            

            
        }
    }

    return 0;
}