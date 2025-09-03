/*
1668A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n, m; cin >> n >>m; 
    vector<int> og(n); 
    for(int i = 0; i < n; ++i){
        cin >> og[i];
    }
    og.push_back(m-1); // dummy var

    int lo = 0, hi = m; 
    while(lo < hi){
        int mid = (lo + hi)/2; 
        auto a = og; 
        bool pos = true; 
        // make everythign as big as possible 
        for(int i = n - 1; i >= 0; --i){
            if(a[i] > a[i+1] && a[i] + mid < m){
                // cannot loop around
                pos = false; break; 
            }
            else if(a[i] > a[i+1]){
                // must loop, and we can loop around
                a[i] = min((a[i] + mid)% m, a[i+1]);  
            }
            else{
                a[i] = min(a[i+1], a[i] + mid); 
            }
        }

        if(pos){
            hi = mid; 
        }
        else lo = mid + 1; 
    }
    cout << lo << "\n";
    return 0;
}