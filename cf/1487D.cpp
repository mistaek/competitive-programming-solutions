/*
1487D
AC
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int ans = (sqrt((2*n)-1) + 1)/2 - 1;
        cout << ans << "\n";
    }
    return 0;
}