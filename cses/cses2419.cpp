/*
cses2419
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int MOD = 1e9+7; 

int fac2[200001]; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    // n log n
    for(int i = 1; i <= 200000; ++i){
        int j = i; 
        while(j){
            fac2[i] += j/2; 
            j /= 2; 
        }
    }

    int n; cin >> n; 
    vector<int> a(n); 
    for(int i = 0; i < n; ++i) cin >> a[i]; 
    int ans = 0; 
    for(int i = 0; i < n; ++i){
        // n - 1 choose i 
        int facs = fac2[n-1] - fac2[i] - fac2[n-i-1];
        if(facs == 0){
            ans ^= a[i]; 
        }
    }
    //cout << fac2[200000] << "\n"; 
    cout << ans << "\n"; 
    return 0;
}