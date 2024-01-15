/*
1898D
AC, dumb math problem which took me too long
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long a[n], b[n];
        long long ans = 0;
        long long s = 0, f = 1e9;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            ans += abs(b[i] - a[i]);
            s = max(s, min(b[i], a[i])); 
            f = min(f, max(a[i], b[i]));
        }
        cout << ans + max(0LL, 2 * (s - f))<< "\n";

    }
    return 0;
}