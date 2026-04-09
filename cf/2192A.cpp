/*
2192A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int blocks = 0, last = 0;
            for(int j = 0; j < n; ++j){
                if(s[(i+j)%n] != last) {
                    last = s[(i+j)%n];
                    ++blocks;
                }
            }
            ans = max(ans, blocks);
        }

        cout << ans << "\n";
    }
    return 0;
}