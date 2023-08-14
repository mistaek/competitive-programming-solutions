/*
1796C
*/

#include <iostream>

using namespace std; 

int main(){
    long long mod = 998244353; // why needed?

    int t; cin >> t; 
    while(t--){
        int l, r; cin >> l >> r; 
        int dif = r/l; 
        int pow = 0, exp = 1; 
        while(exp <= dif){
            pow++; 
            exp *= 2; 
        }
        exp/= 2;
        pow--; 
        int len = pow + 1; 
        long long ans = r/exp; 
        ans -= l- 1;
        ans %= mod; 
        if(exp >= 2){
        exp /= 2; 
        exp *= 3; 
        if(exp <=dif){
            long long temp = r/exp; 
            temp -= l - 1; 
            temp *= pow;
            temp %= mod; 
            ans += temp; 
            ans %= mod; 
        }
        }
        cout << len << " " << ans << "\n";
         

    }

    return 0;
}