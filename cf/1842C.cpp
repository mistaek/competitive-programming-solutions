/*
1842C
AC
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
        int ans[n+1] = {}, best[n+1] = {};
        int a[n+1]; 
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(best[a[i]] == 0){
                best[a[i]] = i; 
                ans[i] = ans[i-1];
            }
            else{
                
                ans[i] = ans[best[a[i]] - 1] + i - best[a[i]] + 1; 
                ans[i] = max(ans[i], ans[i-1]); 


                if(best[a[i]] - 1 - ans[best[a[i]] - 1] > i-1 - ans[i-1]){
                    best[a[i]] = i;
                }
            }
            
        }
        cout << ans[n] << "\n";
    }
    return 0;
}