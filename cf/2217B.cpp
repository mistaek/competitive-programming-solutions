/*
2217B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), special(k);
        for(int i = 0; i < n; ++i){ cin >> a[i];}
        for(int i = 0; i < k; ++i) cin >> special[i];

        int target = a[special[0]-1];

        int frontflip = 0, backflip = 0;
        for(int i = 0; i < special[0] - 1; ++i) {
            if (frontflip % 2 == 0) {
                if (a[i] != target) {
                    ++frontflip;
                }
            }
            else {
                if (a[i] == target) ++frontflip;
            }
        }

        for(int i = special[0]; i < n; ++i) {
            if (backflip % 2 == 0) {
                if (a[i] != target) ++backflip;
            }
            else {
                if (a[i] == target) ++backflip;
            }
        }
        int ans = max(frontflip, backflip);
        if(ans % 2) ++ans;
        cout << ans << "\n";
    }
    return 0;
}