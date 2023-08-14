/*
1811E
AC, cool problem!
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    long long start = 9; 
    for(int i = 0; i < 12; i++) start *= 9; 

    while(t--){
        long long k; cin >> k; 
        long long pow = start; 
        long long ans = 0;
        while(pow){
            long long d = k/pow; 
            if(d >= 4) d++; 
            ans = ans*10 + d; 
            k = k % pow; 
            pow/=9;
        }
        cout << ans << "\n";
    }
    return 0;
}