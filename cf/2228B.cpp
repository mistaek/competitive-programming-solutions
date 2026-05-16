/*
2228A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        long long n, x, y, k;
        cin >> n >> x >> y >> k;
        long long d1 = (y-x + n) % n, d2 = (x - y +n) %n;
        if (min(d1, d2) == 1 && max(d1, d2) <= 2) cout << 1 << "\n";
        else cout << min(d1, d2) + k << "\n";

    }
    return 0;
}