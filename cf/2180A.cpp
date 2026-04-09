/*
2180A
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int l, a, b; cin >> l >> a >> b;
        int best = a;
        for(int i = 0; i <= l; ++i) {
            best = max(best, (a + (i * b)) % l);
        }

        cout << best << "\n";
    }
    return 0;
}