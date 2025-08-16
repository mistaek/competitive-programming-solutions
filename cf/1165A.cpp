/*
1165A
*/

#include <iostream>

using namespace std; 

int main(){

    int n, x, y; cin >> n >> x >> y; 
    int a[n]; 
    for(int i = 0; i < n; ++i){
        char c; cin >> c; 
        a[i] = c - '0'; 
    }

    int ans = 0;
    for(int i = 0; i < x; ++i){
        if(i == y) ans += 1 - a[n - i - 1]; 
        else ans += a[n-i-1]; 
    }
    cout << ans << "\n";
    return 0; 
}