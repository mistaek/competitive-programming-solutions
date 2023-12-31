/*
1917C
ac
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(false); 
    int t; cin >> t; 
    while(t--){
        int n, k, d; cin >> n >> k >> d; 
        int a[n] = {}, b[k] = {};
        int c = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            if(a[i] == i+1) c++; 
        }
        for(int i = 0; i < k; i++){
            cin >> b[i];
        }
        int ans = c + (d-1)/2; 

        for(int i = 0; i < min(2*n + 2, d); i++){
            ans = max(ans, c + (d- i - 1)/2);
            for(int j = 0; j < b[i %k]; j++){
                if(a[j] == j+1) c--; 
                a[j]++;
                if(a[j] == j+1) c++; 
            }
            
        }
        cout << ans << "\n";
    }
    return 0;
}