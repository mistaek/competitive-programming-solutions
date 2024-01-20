/*
1884C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 
    
    int t; cin >> t; 
    while(t--){
        int m, n; cin >> n >> m; 
        vector<pair<int, int>> ivs1, ivsm; 
        vector<pair<int, int>> lr(n); 
        for(int i = 0; i < n; i++){
            cin >> lr[i].first >> lr[i].second; 
            if(lr[i].first > 1){
                ivs1.push_back({lr[i].first, 1}); ivs1.push_back({lr[i].second+1, -1});
            }
            if(lr[i].second < m){
                ivsm.push_back({lr[i].first, 1}); ivsm.push_back({lr[i].second+1, -1});
            }
        }

        sort(ivs1.begin(), ivs1.end()); 
        sort(ivsm.begin(), ivsm.end());
        int cur = 0, idx = 1;
        int mx = 0;
        for(int i = 0; i < ivs1.size(); i++){
            if(ivs1[i].first != idx){
                mx = max(mx, cur);
                idx = ivs1[i].first; 
            }
            cur += ivs1[i].second;
        }

        idx = 1, cur = 0;
        for(int i = 0; i < ivsm.size(); i++){
            if(ivsm[i].first != idx){
                mx = max(mx, cur);
                idx = ivsm[i].first; 
            }
            cur += ivsm[i].second;
        }

        cout << mx << "\n";


    }
    return 0;
}