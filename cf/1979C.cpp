/*
1979C
AC
*/

#include <iostream>
#include <numeric>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long denom = 1, num = 0;
        long long a[n] = {}; 
        long long k[n];
        for(int i = 0; i < n; ++i){
            cin >> k[i];
            denom *= k[i] / gcd(denom, k[i]); 
        }
        for(int i = 0; i < n; ++i){
            a[i] = denom / k[i]; 
            num += a[i]; 
        }

        if(num < denom){
            for(int i = 0; i < n; ++i){
                if(i) cout << " "; 
                cout << a[i]; 
            }
        }
        else cout << "-1"; 
        cout << "\n";

        
    }
    return 0;
}