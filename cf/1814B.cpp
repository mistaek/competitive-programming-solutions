/*
1814B
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int a, b; cin >> a >> b; 
        int lo = 1, hi = min(100000, max(a, b)); 
        int ans = 1e9; 
        for(lo; lo <= hi; lo++){
            int k1 = lo; 
            int ans1 = k1 - 1 + ((a + k1 - 1)/k1) + ((b + k1 - 1)/k1);  
            //cout << k1 <<  " "  << ans1  << "\n";
            ans = min(ans, ans1);
        }
        cout << ans << "\n";
    }
    return 0;
}