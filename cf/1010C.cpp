/*
1010C
AC
*/

#include <iostream>
#include <numeric>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(0); 
    int n, k; cin >> n >> k; 
    int d = k;
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        a %= k; 
        d = gcd(a, d);
    }
    if(d == 0) d = k; 
    cout << k / d <<"\n"; 
    for(int i = 0; i < k; i += d){
        if(i) cout << " "; 
        cout << i; 
    }
    cout << "\n";
    return 0;
}