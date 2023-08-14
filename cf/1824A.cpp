/*
1824A
AC
*/

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        int lc = 0, rc = 0, spec = 0;
        int occ[m+1] = {}, psa[m+1] = {};

        for(int i = 0; i < n; i++){
            int x; 
            cin >> x; 
            if(x == -1) lc++;
            else if(x == -2) rc++;
            else{
                if(occ[x]) continue; 
                else{
                    occ[x] = 1; 
                    spec++;
                }
            }
        }
        for(int i = 1; i <= m; i++){
            psa[i] = psa[i-1] + occ[i];
        }
        int ans = min(m, max(lc + spec, rc + spec)); 
        for(int i = 1; i <= m; i++){

            if(occ[i]){
                int left = min(i, lc+psa[i]);
                int right = min(m-i, psa[m] - psa[i] + rc);
                ans = max(ans, left + right);
            }  
        }
        cout << ans << "\n";
    }
    return 0;
}