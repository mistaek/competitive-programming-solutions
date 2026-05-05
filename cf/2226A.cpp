/*
2226A
*/

#include <iostream>
#include <vector>

using namespace std;

const int mod = 676767677;

int main() {
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n;
        vector<int> a(n);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == 1) continue;
            ans += a[i];
        }
        if(a[n-1] == 1) ++ans;
        cout << ans << "\n";
    }
    return 0;
}