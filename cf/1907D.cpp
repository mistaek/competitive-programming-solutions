/*
1907D
lo
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n][2]; 
        for(int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1]; 
        }

        int lo = 0, hi = 1e9; 
        while(lo < hi){
            int k = (lo + hi)/2; 

            //
            int mn = 0, mx = 0;
            bool pos = true; 
            for(int i = 0; i < n; i++){
                mn -= k; 
                mn = max(0, mn);
                mx += k; 
                
                if(mn > a[i][1] || mx < a[i][0]){
                    pos = false; 
                    break; 
                }
                mn = max(mn, a[i][0]); mx = min(mx, a[i][1]);
            }

            if(pos){
                hi = k; 
            }
            else{
                lo = k+1; 
            }

        }
        cout << lo << "\n"; 
    }
    return 0;
}