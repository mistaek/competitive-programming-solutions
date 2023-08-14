/*
1795
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        int a[51] = {};
        for(int i = 0; i < n; i++){
            int l, r; cin >> l >> r; 
            if(l > k || r < k) continue; 
            for(; l <= r; l++) a[l]++;
        }
        bool ans = true; 
        for(int i = 0; i <= 50; i++){
            if(i == k) continue; 
            if(a[i] >= a[k]) ans = false; 
        }
        if(ans) cout << "yes\n"; 
        else cout << "no\n";
    }
    return 0;
}