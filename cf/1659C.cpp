/*
1659C
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        long long n, a, b; cin >> n >> a >> b;
        vector<long long> x(n), psa(n);

        for(int i = 0; i < n; i++){
            cin >> x[i]; 
            psa[i] = x[i]; 
            if(i) psa[i] += psa[i-1];
        }

        long long ans = psa[n-1] * b;

        for(int i = 0; i < n; i++){
            long long temp = x[i] * a;
            temp += (psa[n-1] - psa[i] - ((n-i-1) * x[i])) *b;
            temp += psa[i] * b; 
            if(i) temp -= psa[i-1] * b; 
            ans = min(ans, temp);
        }

        cout << ans << "\n"; 

    }
    return 0;
}