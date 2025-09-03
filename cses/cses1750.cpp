/*
cses1750
*/
#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    int n, q; cin >> n >> q; 
    int maxK = 31; 
    vector<vector<int>> p(n+1, vector<int>(maxK, -1)); 

    for(int i = 1; i <= n; ++i) cin >> p[i][0];
    for(int k = 1; k < maxK; ++k){
        for(int i = 1; i <= n; ++i){
            int h = p[i][k-1]; 
            if(h != -1){
                p[i][k] = p[h][k-1]; 
            }
        }
    }

    for(int i = 0; i < q; ++i){
        int x, k; cin >> x >> k; 
        int at = x; 
        for(int i = 0; i < maxK; ++i){
            if(at != -1 && (k & (1 << i))){
                at = p[at][i]; 
            }
        }
        cout << at << "\n"; 
    }
    return 0;
}