/*
2115B
AC (with editor)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n, qs; cin >> n >> qs; 
        vector<int> a(n+1); 
        vector<int> mn(n+1), og(n+1);
        vector<pair<int, pair<int, int>>> q(qs); 
        vector<int> lasttouch(n+1, -1); 

        for(int i = 1; i <= n; ++i){
            cin >> a[i]; 
            mn[i] = a[i];
        }
    
        for(int i = 0; i < qs; ++i){
            cin >> q[i].second.first >> q[i].second.second >> q[i].first; 
            lasttouch[q[i].first] = i; 
        }

        for(int i = qs -1; i >= 0; --i){
            int x = q[i].second.first, y = q[i].second.second, z = q[i].first; 
            int sv = mn[z]; mn[z] = 0;
            mn[x] = max(sv, mn[x]);
            mn[y] = max(sv, mn[y]); 
        }

        og = mn;
        //for(int i = 1; i <= n; ++i) cout << og[i] << " ";
        //cout << "\n";
        for(int i = 0; i < qs; ++i){
            mn[q[i].first] = min(mn[q[i].second.first], mn[q[i].second.second]); 

        }

        bool pos = true;
        for(int i = 1; i <= n; ++i){
            if(mn[i] != a[i]) pos = false; 
        }

        if(pos){
            for(int i = 1; i <= n; ++i){    
                cout << og[i] << " "; 
                if(i == n) cout << "\n"; 
            }
        }
        
        if(!pos) cout << "-1\n"; 

    }
    return 0;
}