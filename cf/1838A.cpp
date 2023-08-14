/*
1838A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        bool neg = false;
        int ans = 0; 
        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            if(a < 0){
                neg = true; 
                ans = a; 
            }
            else if(!neg){
                ans = max(ans, a);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}