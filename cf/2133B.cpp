/*
2133B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n, 0); 
        for(int i = 0; i < n; ++i) cin >> a[i]; 
        sort(a.begin(), a.end()); 
        long long ans = 0; 
        for(int i = n-1; i >= 0; i -= 2){
            ans += a[i]; 
        }
        cout << ans << "\n"; 
    }
    return 0;
}