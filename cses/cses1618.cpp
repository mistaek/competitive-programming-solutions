/*
1618
*/

#include <iostream>

using namespace std; 
int main(){
    long long n; 
    long long ans = 0;
    cin >> n; 
    for(long long pow = 5; pow <= n; pow *= 5){
        ans += n/pow; 
    }
    cout << ans << "\n";
    return 0;
}