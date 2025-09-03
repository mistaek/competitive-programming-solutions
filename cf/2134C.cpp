/*
2134C
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        long long a[n]; 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }
        long long ans = 0; 
        for(int i = 1; i < n; i+=2){
            long long sumSides = a[i-1]; 
            if(i + 1 < n) sumSides += a[i+1]; 
            long long delta = sumSides - a[i]; //need to reduce by this much 
            if(delta <= 0) continue; 
            if(i+1 < n){
                long long diff = min(delta, a[i+1]); 
                ans += diff; 
                a[i+1] -= diff; 
                delta -= diff; 
            }
            if(delta <= 0) continue; 
            long long diff = min(delta, a[i-1]); 
            ans += min(delta, a[i-1]); 
            a[i-1] -= diff; 
        }
        cout << ans << "\n"; 
    }
    
    return 0;
}