/*
1867E1
ac
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        int cur = 1; 
        int ans = 0; 
        while(n - cur+1>= k){
            int res; 
            cout << "? " << cur << endl; 
            cin >> res; 
            ans ^= res; 
            cur +=k;
        }
        // deal with overlap
        //reset last k + ?? of array
        if(n % k == 0){
            cout << "! " << ans << endl;
        }
        else{
            cur -= k - 1;
            int res; 
            while(cur <= n-k+1){
                cout << "? " << cur << endl; 
                cin >> res; 
                ans ^= res; 
                cur++;
            }
            cout << "! " << ans << endl;
        }

    }
    return 0;
}