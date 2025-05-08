/*
1153B
*/

#include <vector>
#include <iostream>

using namespace std; 

int main(){
    int n, m, h; cin >> n >> m >> h; 
    int front[m], left[n]; 
    for(int i = 0; i < m; ++i) cin >> front[i];
    for(int i = 0; i < n; ++i) cin >> left[i]; 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j) cout << " "; 
            int block = 0; 
            cin >> block; 
            if(block == 1){
                block = min(front[j], left[i]); 
            }
            cout << block; 
        }
        cout << "\n";
    }

    
    return 0;
}