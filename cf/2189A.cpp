/*
2189A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--){ 
        int n, h, l; cin >> n >> h >> l;
        if (h > l) swap(h, l);
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int bigH, bigL; // number of entries smaller than h or l
        bigH = upper_bound(a.begin(), a.end(), h) - a.begin();
        bigL = upper_bound(a.begin(), a.end(), l) - a.begin();

        cout << min(bigH, bigL/2) << "\n";

    }
    return 0;
}