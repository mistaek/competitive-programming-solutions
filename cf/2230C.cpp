/*
2230B
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long total = 0;
        long long slots = 0, singles = 0;
        long long ans = 0;

        long long cnt = 0;
        for(int i = 0; i < n; ++i) {
            long long c; cin >> c;
            if (c >= 2) ++cnt;
            if (c >= 2) {
                slots += (c/2) - 1;
            }

            if(c == 1) singles++;
            else ans += c;
            total += c;
        }
        if(cnt == 1) ++slots;

        if(total < 3) {
            cout << "0\n";
            continue;
        }
 
        ans += min(singles, slots);
        if(ans < 3) cout << 0 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}