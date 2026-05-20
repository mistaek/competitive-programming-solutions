/*
2230A
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (3 * a <= b) {
            cout << n * a << "\n";
        }
        else {
            long long ans = (n/3) * b;
            long long rem = n % 3;
            ans += min(rem * a, b);
            cout << ans << "\n";
        }
    }
    return 0;
}