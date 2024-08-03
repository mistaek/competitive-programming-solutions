/*
1862F
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int dp[1000001] = {}; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        long long w, f; cin >> w >> f; 
        int n; cin >> n; 
        int s[n]; 
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> s[i];
            sum += s[i];
        }
        for(int i = 0; i <= 1000000; ++i){
            dp[i] = i; 
        }
        for(int i = n-1; i >= 0; --i){
            for(int j = 1000000; j >= 0; --j){
                if(j < s[i]) continue; 
                dp[j] = min(dp[j], dp[j-s[i]]); 
            }
        }

        int lo = 1, hi = 1e6; 
        while(lo < hi){
            long long mid = (lo + hi)/2; 
            long long wm = mid * w, fm = mid * f; 
            bool pos = false; 
            if(wm > 1000000 || fm > 1000000) pos = true; 
            else{
                if(fm >= sum - wm + dp[wm]) pos = true; 
            }
            if(pos){
                hi = mid; 
            }
            else{
                lo = mid+1; 
            }
        }
        cout << lo << "\n";
    }
}