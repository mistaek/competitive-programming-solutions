/*
1651C
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
        int n; cin >> n; 
        vector<long long> a(n), b(n); 
        for(int i = 0; i < n; i++) cin >> a[i]; 
        for(int i = 0; i < n; i++) cin >> b[i];

        long long r1c1 = a[0], r1c2 = a[n-1], r2c1 = b[0], r2c2 = b[n-1];
        long long ans = r1c1 + r1c2 + r2c1 + r2c2; 

        long long r1c1b = b[0], r1c2b = b[0], r2c1b = a[0], r2c2b = a[0]; 
        for(int i = 0; i < n; i++){
            if(abs(r1c1b - r1c1) > abs(r1c1 - b[i])) r1c1b = b[i];
            if(abs(r1c2b - r1c2) > abs(r1c2 - b[i])) r1c2b = b[i];
            if(abs(r2c1b - r2c1) > abs(r2c1 - a[i])) r2c1b = a[i];
            if(abs(r2c2b - r2c2) > abs(r2c2 - a[i])) r2c2b = a[i];
        } 
        long long r1c1o[] = {r2c1, r1c1b, r2c2}, r1c2o[] = {r2c1, r1c2b, r2c2};
        //cout << r1c1b << " " << r1c2b << " " << r2c1b << " " << r2c2b << "\n";
        for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < 3; j++){
                
                int filled[3] = {};
                long long res = 0;
                filled[i] = 1;
                res = 0;
                res += abs(r1c1 - r1c1o[i]);
                res += abs(r1c2 - r1c2o[j]);
                filled[j] = 1;
                if(!filled[0]) res += abs(r2c1 - r2c1b); 
                if(!filled[2]) res += abs(r2c2 - r2c2b);
                ans = min(ans, res);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}