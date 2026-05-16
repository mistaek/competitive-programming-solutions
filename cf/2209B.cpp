/*
2209C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n);

        for(int i = 0; i < n; ++i) cin >> a[i];

        for(int i = 0; i < n; ++i) {
            long long low = 0, hi = 0;
            for(int j = i+1; j < n; ++j) {
                if (a[j] > a[i]) ++hi;
                else if (a[j] < a[i]) ++low;
            }

            if(i) cout << " ";
            cout << max(low, hi);
        }
        cout << "\n";
    }
    return 0;
}