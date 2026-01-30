/*
2182B
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--) {
        int a, b; cin >> a >> b;
        if(a < b) swap(a, b);
        int big = 1, small = 0, pow = 2;
        int ans = 0;
        while(true) {
            if(a >= big && b >= small) ++ans;
            else break;
            swap(big, small);
            big += pow; 
            pow *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}