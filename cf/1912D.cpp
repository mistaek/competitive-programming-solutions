/*
1912D
ac
*/

#include <iostream>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(false); 

    int t; cin >> t; 
    while(t--){
        long long b, n; cin >> b >> n; 
        int vis[n] = {};
        
        long long pow = 1; 
        long long ans = 0, k = 0; 
        for(int i = 0; i < n; i++){
            pow *= b; 
            pow %= n; 
            if(vis[pow]){
                ans = 0, k = -1; break; 
            }
            vis[pow] = 1;

            if(pow == 0){
                ans = 1; k = i+1;
                break; 
            }
            else if(pow == 1){
                ans = 2; k = i+1;
                break; 
            }
            else if(pow == n-1){
                ans = 3; k = i+1;
                break;
            }
        }
        if(ans == 0) cout << ans << "\n"; 
        else cout << ans << " " << k << "\n";
    }
    return 0;
}