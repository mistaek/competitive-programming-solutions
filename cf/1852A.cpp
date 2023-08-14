/*
1852A
AC
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        long long a[n]; 

        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        if(a[0] > 1){
            cout << 1 << "\n"; 
            continue; 
        }
        long long cur = 1; 
        for(int i = 0; i < k; i++){
            long long lo = cur + 1, hi = cur + n; 
            while(lo < hi){
                long long mid = (lo + hi)/2; 
                long long j = mid - cur - 1; 
                if(a[j + 1] > mid && mid > a[j]){
                    lo = mid;
                    break; 
                }
                else{
                    if(a[j+1] <= mid){
                        lo = mid+1; 
                    }
                    else{
                        hi = mid-1; 
                    }
                }
            }
            cur = lo; 
        }
        cout << cur << "\n";
    }
    return 0;
}