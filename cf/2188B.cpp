/*
2188B
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> bs(n+2);
        bs[0] = 0; bs[n+1] = 0;
        int ans = 0;
        for(int i = 1; i<= n; ++i) {
            char c; cin >> c;
            if(c == '0') bs[i] = 0;
            else bs[i] = 1;
        }

        ans += bs[1];
        for(int i = 2; i <= n+1; ++i) {
            if(bs[i-1] == 0 && bs[i-2] == 0) bs[i] = 1;
            ans += bs[i];
        }
        
        cout << ans << "\n";
    }
    return 0;
}