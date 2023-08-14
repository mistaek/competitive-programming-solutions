/*
1797C
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        cout << "? 1 1" << endl; 
        int ans, ans2, ans3; 
        cin >> ans; 
        ans++;
        if(ans > n){
            cout << "? 1 " << ans << endl; 
            cin >> ans2;
            ans2++; 
            cout << "! " << ans2 << " " << ans << endl;
        }
        else if(ans > m){
            cout << "? " << ans << " 1" << endl; 
            cin >> ans2;
            ans2++; 
            cout << "! " << ans << " " << ans2 << endl; 
        }
        else{
            cout << "? 1 " << ans << endl; 
            cin >> ans2; 
            ans2++;
            cout << "? " << ans << " 1" << endl; 
            cin >> ans3; 
            ans3++;
            if(ans3 < ans2){
                cout << "! " << ans << " " << ans3 << endl; 
            }
            else {
                cout << "! " << ans2 << " " << ans << endl; 
            }
        }
    }
    return 0;
}