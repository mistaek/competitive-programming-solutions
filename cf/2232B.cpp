/*
2232B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long curh = a[0], curLeftovers = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] + curLeftovers < curh) {
                // find newh such that a[i] + curleftovers + (curh-newh) * i > newh
                // a[i] + curl + i*curh > (i+1) * newh
                long long newh = (a[i] + curLeftovers + i * curh)/(i+1);
                curLeftovers += i*(curh-newh);
                curLeftovers += a[i]-newh;
                curh = newh;
            }
            else {
                curLeftovers += a[i]-curh;
            }

            if (i) cout << " ";
            cout << curh;
        }
        cout << "\n";
    }
    return 0;
}