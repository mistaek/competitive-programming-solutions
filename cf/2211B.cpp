/*
2211A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const long long MOD = 676767677;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long x, y; cin >> x >> y;
        if(x > 0 && y > 0) {
            long long diff = abs(x - y);
            long long ans = 0;
            if(diff == 0) ans = 1;
            else {
                for(int i = 1; i * i <= diff; ++i) {
                    if(diff % i == 0) ans++;
                    else continue;
                    if(diff / i != i) ans++;
                    ans %= MOD;
                }
            }
            cout << ans << "\n";
            for(int i = 0; i < x; ++i) {
                if(i) cout << " ";
                cout << 1;
            }
            for(int i = 0; i < y; ++i) cout << " " << -1;
            cout << "\n";
        }
        else {
            int out = 1;
            if(x == 0){
                swap(x, y);
                out = -1;
            }
            long long ans = 0;
            for(long long i = 1; i * i <= x; i++) {
                if(x % i == 0) ans++;
                else continue;
                if(x/i != i) ans++;
                ans %= MOD;
            }
            cout << ans << "\n";
            for(int i = 0; i < x; ++i){
                if(i) cout << " ";
                cout << out;
            }
            cout << "\n";
        }
    }
    return 0; 
}