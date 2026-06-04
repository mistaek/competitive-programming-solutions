/*
2231B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t-- ){
        int n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; ++ i){
            cin >> a[i];
        }
        
        bool ans = true;
        long long maxgap = 0;
        for(int i = 1; i < n; ++i) {
            if (a[i] < a[i-1]) {
                maxgap = max(a[i-1]-a[i], maxgap);
            }
        }

        for(int i = 0; i < n; ++i) {
            if (i && a[i] < a[i-1]) a[i] += maxgap;
            if (i && a[i] < a[i-1]) {
                ans = false;
            }
        }

        if (!ans) {
            cout << "NO\n";
        }
        else cout << "YES\n";

    }
    return 0;
}