/*
1781D
AC
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std; 

bool isroot(long long n){
    long long rt = sqrt(n); 
    return rt * rt == n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin>>n; 
        long long a[n]; 
        long long ans = 0; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ans += isroot(a[i]); 
        }
        ans = max(1LL, ans);
        for(int i = 0; i <n; i++){
            for(int j = i+1; j < n; j++){
                long long diff = a[j] - a[i];
                for(long long f = 1; f *f <= diff; f++){
                    long long p = diff/f; 
                    if(f * p != diff) continue; 
                    long long b = (f + p) /2, c = p - b;

                    if(((b+c) * (b - c)) != diff) continue; 
                    if(b * b < a[j] || c * c < a[i]) continue; 
                    long long x = b* b - a[j]; 
                    
                    long long test = 0;
                    for(int k = 0; k < n; k++){
                        if(isroot(a[k] + x)) test++; 
                    } 
                    /*
                    cout << diff << " " << f << " " << p << " " << c << " " << b << "\n";
                    cout << x << " " << test << "\n"; 
                    */
                    ans = max(ans, test);

                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}