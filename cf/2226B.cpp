/*
2226B
*/

#include <iostream>
#include <vector>

using namespace std;

const int mod = 676767677;

int main() {
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n;
        vector<int> a(n), pos(n+1, -1);
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        for(int i = 1; i < n; ++i) {
            for (int j = i; j < n; j += i) {
                // check for subarray where min is j and diff is i
                if(j+i > n) break;
                // must be next to each other
                if (abs(pos[j] -pos[j+i]) == 1) ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}