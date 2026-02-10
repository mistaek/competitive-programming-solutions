/*
2194A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<string> s(k);
        vector<int> masks(n, 0);
        for(int i = 0; i < k; ++i) cin >> s[i];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < k; ++j) {
                masks[i] |= (1 << (s[j][i] - 'a'));
            }
        }

        int ans = n;
        for(int i = 1; i <= n/2; ++i) {
            if(n % i == 0) {
                int pos = true;
                for(int j = 0; j < i; ++j){
                    int mask = masks[j];
                    for(int k = 1; k < n/i; ++k) mask &= masks[j+k*i];
                    if(!mask) {
                        pos = false; break;
                    }
                }
                if(pos) {
                    ans = i; break;
                }
            }
        }

        string anss;
        for(int j = 0; j < ans; ++j){
            int mask = masks[j];
            for(int k = 1; k < n/ans; ++k) mask &= masks[j+k*ans];
            for(int i = 0; i < 26; ++i) {
                if(mask & (1 << i)) {
                    anss.push_back((char)('a' + i));
                    break;
                }
            }
        }

        for(int i = 0; i < n/ans; ++i) cout << anss;
        cout << "\n";
    }
    return 0;
}