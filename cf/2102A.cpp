/*
2102A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n, m, p, q; 
        cin >> n >> m >> p >> q; 
        int mins = (n/p) * q; 
        if(mins == m || (n % p)) cout << "YES\n"; 
        else cout << "NO\n";
    }

    return 0;
}