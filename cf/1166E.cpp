/*
1166E
*/

#include <iostream>
#include <bitset>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int m, n; cin >> m >> n; 
    vector<bitset<10000>> sets(m);
    for(int i = 0; i < m; ++i){
        int s; cin >> s; 
        for(int j = 0; j < s; ++j){
            int ind; cin >> ind; 
            sets[i][ind-1] = 1;
        }
    } 

    bool pos = true; 
    for(int i = 0; i < m; ++i){
        for(int j = i+1; j < m; ++j){
            auto ans = sets[i] & sets[j]; 
            if(ans.count() == 0){
                pos = false; break; 
            }
        }
    }
    if(!pos) cout << "im"; 
    cout << "possible\n"; 
    return 0;
}