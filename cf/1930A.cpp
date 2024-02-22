/*
1930A
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long ans = 0; 
        for(int i = 0; i < 2*n; i+= 2) ans += a[i];

        cout << ans << "\n";
    }
    return 0;
}