/*
1920C
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int gcd(int a, int b){
    if(b == 0) return a; 
    else return gcd(b, a%b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int ans = 1; // k = n always works
        for(int k = 1; k < n; k++){
            if(n % k == 0){
                int cgcd = -1;
                for(int i = 0; i < n-k; i++){
                    if(a[i] == a[i+k]) continue; //any cgcd will work
                    if(cgcd == -1) cgcd = abs(a[i+k] - a[i]);
                    else cgcd = gcd(abs(a[i+k] - a[i]), cgcd);
                }
                if(cgcd != 1) ans++;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}