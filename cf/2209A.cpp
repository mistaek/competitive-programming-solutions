/*
2209A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long c, k; cin >> c >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; ++i) {
            if(a[i] > c) break;

            long long flipflops = min(k, c-a[i]);
            a[i] += flipflops;
            k -= flipflops;

            c += a[i];
        }

        cout << c << "\n";
    }
    return 0;
}