/*
888D
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    long long n, k; cin >> n >> k; 

    long long ans = 1; 
    if(k >= 2) ans += n * (n-1)/2;  // n choose 2, !2 = 1
    if(k >= 3) ans += n * (n-1) * (n-2) / 3; 
    if(k >= 4) ans += 3LL * n * (n-1) * (n-2) * (n-3) / 8;
    cout << ans << "\n"; 
    return 0;
}