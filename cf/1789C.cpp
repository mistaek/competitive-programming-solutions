/*
1789C
*/

#include <iostream>
#include <map>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        int a[n]; 
        map<int, map<int, int>> gen;
        int lc[n] = {}; 
        //total generations, last change
        for(int i = 0; i < n; i++){
            cin >> a[i];
            gen[i][a[i]] = 0;
        }


        
        for(int i = 0; i < m; i++){
            int p, v; cin >> p >> v; 
            p--;
            if(a[p] == v) continue; 
            gen[p][a[p]] += i + 1 - lc[p];
            a[p] = v; 
            lc[p] = i+1; 

        }
        //last upd 
        for(int i = 0; i < n; i++){
            gen[i][a[i]] += m+1-lc[i];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            int tot = m+1;
            for(auto kvp : gen[i]){
                //cout << i << " " << kvp.first << " " << kvp.second << "\n";
                ans+= (kvp.second)*(tot-kvp.second); 
                tot-= kvp.second;
            }
        }
        cout << ans << "\n"; 
        ans += (((m+1)*(m))/2) * n;
        cout << ans << "\n";
    }
    return 0;
}