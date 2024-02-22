/*
1867E2
AC EZ
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int cur = 1, d = n/k, ans = 0;
        for(int i = 0; i < d; i++){
            int resp;
            cout << "? " << cur << endl; 
            cur += k; 
            cin >> resp; ans ^= resp; 
        }
        if(n % k == 0){
            cout << "! " << ans << endl; 
            continue; 
        }
        d = n % k; //this will be even. 
        d/= 2; 
        int resp; 
        cout << "? " << n - d - k + 1 << endl; 
        cin >> resp; 
        ans ^= resp; 
        cout << "? " << n - k + 1 << endl; 
        cin >> resp; 
        ans ^= resp;

        cout << "! " << ans << endl;
    }
     
    return 0;
}