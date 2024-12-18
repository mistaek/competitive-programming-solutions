/*
992B
*/

#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std; 

int main(){ 
    long long l, r, x, y; 
    cin >> l >> r >> x >> y; 

    if(y % x){
        cout << 0 << "\n"; 
        return 0;
    }

    long long yx = y/x; 
    long long ans = 0; 
    for(long long i = 1; i * i <= yx; ++i){
        long long j = yx/i; 
        if(i * j == yx){
            long long a = x * i, b = x * j; 
            if(gcd(a, b) == x && l <= a && b <= r){
                ans += 2; 
                if(a == b) --ans; 
            }
        }
    }
    cout << ans << "\n";
    return 0;
}