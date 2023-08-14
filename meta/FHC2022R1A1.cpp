/*
FHC2022R1A1
*/

#include <iostream>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int t; cin >> t; 
    for(int tc = 1; tc <= t; tc++){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        int a1 = 0, b1 = 0; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1) a1 = i; 
        }
        for(int i =0; i < n; i++){
            cin >> b[i];
            if(b[i] == 1) b1 = i; 
        }

        int diff = b1-a1; diff %= n; 
        if(diff < 0) diff += n; 
        bool ans = true; 
        for(int i = 0; i < n; i++){
            int idx = i + diff; 
            idx %= n;
            if(a[i] != b[idx]){ ans = false;}
        }
        cout << "Case #" << tc << ":";
        if(!ans) cout << " NO\n";
        else if(n == 2){
            if(diff % 2 == k % 2) cout << " YES\n"; 
            else cout << " NO\n";
        }
        else{
            if(diff > 0){
                if(k) cout << " YES\n"; 
                else cout << " NO\n";
            }
            else{
                if(k != 1) cout << " YES\n"; 
                else cout << " NO\n";
            }
        }
        
    }
    return 0;
}