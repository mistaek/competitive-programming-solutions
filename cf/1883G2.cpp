/*
1883G2
AC
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        long long n, m; 
        cin >> n >> m; 
        long long a[n-1], b[n];
        for(int i = 0; i < n-1; i++){
            cin >> a[i]; 
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        sort(a, a+n-1);
        sort(b, b+n);
        int j = 0;
        int matched[n] = {};
        for(int i = 0; i < n-1; i++){
            while(j < n && b[j] <= a[i]) j++;
            if(j == n) break; 

            // a[i] < b[j] should always be true after loop above
            matched[j] = 1; 
            j++;
        }
        long long ans = 0, mx = 0, unmatched = 0; 
        for(int i = 0; i < n; i++){
            if(matched[i] == 0){
                unmatched++; 
                mx = b[i];
            }
        }

        ans = (unmatched * m) - min(mx - 1, m); 
        cout << ans << "\n";

    }
    return 0;
}