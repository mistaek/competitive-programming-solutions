/*
1899F
AC
*/

#include <iostream>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n, q; cin >> n >> q; 
        for(int i = 1; i < n; i++){
            cout << i << " " << i+1 << "\n";
        }
        int cur = n-1; 
        for(int i = 0; i < q; i++){
            int d; cin >> d; 
            if(d == cur){
                cout << -1 << " " << -1 << " " << -1 << "\n";
            }
            else{
                cout << n << " " << cur << " " << d << "\n"; 
            }
            cur = d; 
        }
    }
    return 0;
}