/*
1772D
AC - editorial impl
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std; 

int main(){
    long long t; cin >> t; 
    while(t--){
        long long n; cin >> n;
        long long a[n];

        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }
        long long ans = a[0];
        long long mn = 0, mx = 1e9; 
        for(long long i = 0; i < n-1; i++){
            long long lmid, rmid; 
            lmid = (a[i] + a[i+1] )/2; 
            rmid = (a[i] + a[i+1] + 1)/2; 
            long long m, M; 
            if(a[i+1] < a[i]){
                m = rmid, M = 1e9; 
            }
            else if(a[i+1] == a[i]) continue; 
            else{
                m = 0, M = lmid; 
            }
            
            if(mn > M || mx < m){
                ans = -1; 
            }
            mn = max(mn, m); mx = min(M, mx);
        }
        if(ans != -1) ans = mn; 
        cout << ans << "\n";

    }
    return 0;
}