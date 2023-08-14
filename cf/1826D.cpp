/*
1826D
ac
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std; 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int pa[n]= {}, sa[n] = {};
        sa[n-1] = -1e9; 
        pa[0] = -1e9;
        for(int i = 0; i < n; i++){
            if(i) pa[i] = pa[i-1]; 
            if(a[i] + i +1 > pa[i]) pa[i] = a[i] + i+1; 
        }
        for(int i = n-1; i >= 0; i--){
            if(i != n-1){
                sa[i] = sa[i+1];
            }
            if(a[i] - i -1 > sa[i]) sa[i] = a[i] - i-1;
            
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = max(ans, a[i] + sa[i+1] + pa[i-1]);
        }
        cout << ans << "\n";
    }
    return 0;
}