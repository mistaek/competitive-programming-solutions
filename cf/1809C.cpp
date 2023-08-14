/*
1809C
AC
*/

#include <iostream>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> ans(n, -2); 


        int idx = n-1; 
        while(k){
            if(k <= idx + 1){
                ans[idx] = 2 *(k-1) + 1; 
                k = 0;
            }
            else{
                ans[idx] = 2* idx + 1; 
                k -= idx+1; 
                idx--; 
            }
        }
        for(int i = 0; i < n; i ++){
            if(i) cout << " "; 
            cout << ans[i]; 
        }
        cout << "\n";
        
    }
    return 0;
}