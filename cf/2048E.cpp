/*
2048E
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 

    while(t--){
        int n, m; cin >> n >> m; 
        if(2 * n <= m){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            int colors[m][2*n] = {};//2e6
            for(int color = 1; color <= n; ++color){
                for(int j = 0; j < m; ++j){
                    colors[j][(2*color + j-2) % (2*n)] = color;
                    colors[j][(2*color + j - 1) % (2*n)] = color;
                }
                
            }
            for(int i = 0; i < 2*n; ++i){
                for(int j = 0; j < m; ++j){
                    if(j) cout << " "; 
                    cout << colors[j][i]; 
                }
                cout << "\n";
            }
        }
    }
    return 0;
}