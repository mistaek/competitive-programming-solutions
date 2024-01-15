/*
1920B
AC
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
        int n, k, x; cin >> n >> k >> x; 
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        sort(a.begin(), a.end());

        long long ans = 0, best = 0; 
        for(int i = 0; i < n- x; i++){
            ans += a[i];
        }
        for(int i = n -x; i < n; i++){
            ans -= a[i];
        }
        best = ans; 
        for(int i = 0; i < k; i++){
            int diff = a[n-i-1] - ((n - i - 1 - x >= 0) ? (2*a[n-i-1-x]) : 0); 
            ans += diff; 
            best = max(ans, best); 
        }

        cout << best << "\n";
    }

    
    return 0;
}