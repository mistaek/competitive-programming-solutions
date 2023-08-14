/*
1499C
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
        vector<long long> c(n); 
        for(int i = 0; i < n; i++) cin >> c[i];

        long long c1 = c[0] * n, c2 = c[1] * n, s1 = c[0], s2 = c[1], m1 = c[0], m2 = c[1];
        long long ans = c1 + c2; 
        for(int i = 2; i < n; i++){
            if(i % 2){
                s2 += c[i]; 
                m2 = min(m2, c[i]); 
                c2 = s2 + (n-(i/2) - 1) * m2; 
                ans = min(ans, c1 + c2);
            }
            else{
                s1 += c[i]; 
                m1 = min(m1, c[i]); 
                c1 = s1 + (n - (i/2) - 1) * m1; 
                ans = min(ans, c1 + c2);
            }
        }

        cout << ans << "\n"; 
    }
    return 0;
}