/*
2189E
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--){ 
        int n; cin >> n; 
        string s; cin >> s;
        vector<int> pref(n, 0), suf(n, 0);
        for(int i = 0; i < n; ++i) {
            if(i) pref[i] = pref[i-1];
            if(s[i] == '1') ++pref[i];
        }
        for(int i = n-1; i >= 0; --i) {
            if(i < n-1) suf[i] = suf[i+1];
            if(s[i] == '1') ++suf[i];
        }

        if(n == 1 && s[0] == '1') {
            cout << 0 << "\n";
            continue;
        }
        if(pref[n-1] >= (n+1)/2) {
            cout << n << "\n";
            continue;
        }
        if(pref[n-1] == 0) {
            cout << "-1\n";
            continue;
        }
        if(s[0] == '1' || s[n-1] == '1') {
            cout << n+1 << "\n";
            continue;
        }

        int ans = n+3;
        for(int i = 1; i < n-1; ++i) {
            if(s[i] == '0') {
                int leftDelta = pref[i-1] + pref[i-1] -i;
                int rightDelta = suf[i] + suf[i+1] - (n-i-1);
                if(leftDelta >= 0 && rightDelta >= 0) ans = min(ans, n+1);
                if(leftDelta >= 1) ans = min(ans, n+1);
                if(rightDelta >= 1) ans = min(ans, n+1);
            }
            else {
                int leftDelta = pref[i] + pref[i-1] - i;
                int rightDelta = suf[i] + suf[i+1] - (n-i -1);

                if(leftDelta >= 0) {
                    ans = min(ans, n + 2);
                    if(leftDelta >= 1 || i == n-2) ans = min(ans, n+1);
                }
                if(rightDelta >= 0){
                    ans = min(ans, n+2);
                    if(rightDelta >= 1 || i == 1) ans = min(ans, n+1);
                }
                if(leftDelta >= 0 && rightDelta >= 0) ans = min(ans, n+1);
                if(s[i-1] == '1') ans = min(ans, n+2);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}