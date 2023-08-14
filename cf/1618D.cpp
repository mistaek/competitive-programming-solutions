/*
1618D
AC 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin>>t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int ans = 0; 
        vector<int> a(n); 
        for(int i = 0; i <n ;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end()); 

        for(int i = 0; i < n-(2*k); i++){
            ans += a[i];
        }
        for(int i = n - (2*k); i < n-k; i++){
            ans += a[i]/a[i+k];
        }
        cout << ans << "\n"; 

    }
    return 0;   
}