/*
1717B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, k, r, c; cin >> n >> k >> r >> c; 
        char grid[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = '.';
            }
        }
        grid[r-1][c-1] = 'X';
        
        int sc = c - r, sr = r - c;
        sc %= k; 
        sr %= k; 
        while(sc < 0) sc += k; 
        while(sr < 0) sr += k; 
        sc %= k;
        sr %= k; 
        while(sc < n){
            for(int i = 0; i < n-sc; i++){
                grid[i][i + sc] = 'X';
            }
            sc += k; 
        }
        while(sr < n){
            for(int j = 0; j < n - sr; j++){
                grid[j+ sr][j] = 'X'; 
            }
            sr += k; 
        }
                

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j]; 
            }
            cout << "\n";
        }
        
        
    }
    
    return 0;
}