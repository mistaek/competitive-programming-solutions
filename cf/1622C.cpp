/*
1622C
AC :)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        long long n; long long k, sum = 0; cin >> n >> k; 

        vector<long long> a(n); 
        for(long long i = 0; i < n; i++){ 
            cin >> a[i]; 
            sum += a[i];
        }
        sort(a.begin(), a.end());

        vector<long long> delta(n); 
        for(int i = 1; i < n; i++){
            delta[i] = a[i] - a[0];
            delta[i] += delta[i-1];
        }

        long long lo = 0, hi = max(0LL, sum-k);
        while(lo < hi){
            long long mid = (lo + hi)/2, ns = sum;
            //cout << lo << " " << mid << " " << hi << "\n"; 
            long long mod = max(0LL, mid-n+1);
            long long steps = min(n-1, mid);
            for(long long i = n-steps; i <n; i++){
                ns = min(ns, sum - ((n-i+1)*(mod)) - (delta[n-1] - delta[i-1])); 
                mod++;
            }

            if(ns <=k){
                hi = mid; 
            }
            else lo = mid+1; 
        }

        cout << lo << "\n";
        

        
    }

    return 0;
}