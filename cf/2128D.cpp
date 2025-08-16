/*
2128A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<long long> p(n), lds(n, 0); 
        for(int i = 0; i < n; ++i){
            cin >> p[i]; 
        }
        // lds[i] = sum of LDS lengths for all intervals starting at i 
        // = len(lds[i, i] + lds[i, i+1], ... lds[i, n]); 
        // theoretically only need to store 2 values but wtv. 
        long long ans = 1; 
        lds[n-1] = 1; 
        for(int i = n-2; i >= 0; --i){
            if(p[i] > p[i+1]){
                lds[i] = lds[i+1] + (n - i); 
            }
            else{
                lds[i] = lds[i+1] + 1; 
            }
            ans += lds[i]; 
        }

        cout << ans << "\n"; 
    }
    return 0;
}