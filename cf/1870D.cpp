/*
1870D
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long c[n]; 
        for(int i = 0; i < n; i++){
            cin >> c[i]; 
        }
        long long k; cin >> k;
        vector<int> mins;         
        for(int i = n-1; i >= 0; i--){
            if(mins.empty() || c[i] < c[mins.back()]){
                mins.push_back(i);
            }
        }

        reverse(mins.begin(), mins.end());
        long long prevm = k/c[mins[0]], curc = prevm*c[mins[0]], previ  =0;
        long long ans[n] = {}; ans[0] = prevm; 
        long long ctr =0;
        for(ctr = 0; ctr <= mins[0]; ctr++){
            ans[ctr] = prevm; 
        }
        for(int i = 1; i < mins.size(); i++){
            long long lo = 0, hi = prevm; 
            while(lo < hi){
                long long mid = (lo + hi+1)/2; 
                if(curc + mid*(c[mins[i]] - c[mins[previ]])<= k){
                    lo = mid; 
                }
                else{
                    hi = mid-1; 
                }
            }
            for(ctr; ctr <= mins[i]; ctr++){
                ans[ctr] = lo;
            }
            if(lo){ curc += lo *(c[mins[i]] - c[mins[previ]]); previ = i; prevm = lo; }
        }

        for(int i = 0; i < n;  i++){
            if(i) cout << " ";
            cout << ans[i]; 
        }
        cout << "\n";
    }
    return 0;
}