/*
1838A
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    bool prime[1001] = {true, true};
    for(int i = 2; i <=  1000; i++){
        if(prime[i]) continue; 
        for(int j = i*i; j <= 1000; j+= i){
            prime[j] = true; 
        }
    }
    while(t--){
        int n, m; cin >> n >> m; 
        int grid[n][m] = {}; 
        grid[0][0] = 1; 
        if(prime[m]){ 
            for(int i = 1; i < n; i++){
                grid[i][0] = grid[i-1][0] + m; 
            }
            for(int i = 0; i < n; i++){
                for(int j = 1; j < m; j++){
                    grid[i][j] = grid[i][j-1] + 1; 
               }
            }
        }
        else if(prime[n]){
            for(int j = 1; j < m; j++){
                grid[0][j] = grid[0][j-1] + n; 
            }
            for(int j = 0; j < m; j++){
                for(int i = 1; i < n; i++){
                    grid[i][j] = grid[i-1][j] + 1; 
                }
            }
        }
        else{
            int ctr = 1; 
            for(int i = 2; i < n; i+=2){
                grid[i][0] = grid[i-2][0]+ m; 
                ctr += m; 
                
            }
            for(int i = 1; i < n; i+= 2){
                grid[i][0] = ctr + m; 
                ctr += m;
            }
            for(int i = 0 ; i < n; i++){
                for(int j = 1; j < m; j++){
                    grid[i][j] = grid[i][j-1] + 1; 
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j) cout << " "; 
                cout << grid[i][j]; 
            }
            cout << "\n"; 
        }
        cout << "\n";
    }
    return 0;
}