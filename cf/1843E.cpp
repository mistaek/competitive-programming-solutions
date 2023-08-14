/*
1843E
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> left(n+1);
        for(int i = 0; i < m; i++){
            int l, r; cin >> l >> r; 
            left[l].push_back(r);
        }

        int q; cin >> q; 
        int lo[n+1], hi[n+1], cnt[n+1];
        while(q--){
            int x; cin >> x; 
            int l = x, r = x;
            if(lo[x] == 0){
                lo[x] = x; 
                hi[x] = x; 
            }
            else{
                l = lo[x];
                r = hi[x]; 
                while(lo[l] != l){
                    l = lo[l];
                }
            }
        }
    }
    return 0;
}