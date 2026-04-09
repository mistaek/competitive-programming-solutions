/*
2197F
*/

#include <iostream>
#include <set>
#include <string>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        int ans = 0;
        set<int> roundO, roundC, squareO, squareC;
        for(int i = 0; i < n; ++i) {
            if(s[i] == ']') {
                if(squareO.size()) {
                    squareO.erase(prev(squareO.end()));
                }
                else squareC.insert(i);
            }
            else if(s[i] == ')') {
                if(roundO.size()) {
                    roundO.erase(prev(roundO.end()));
                }
                else roundC.insert(i);
            }
            else if(s[i] == '[') {
                squareO.insert(i);
            }
            else if(s[i] == '(') {
                roundO.insert(i);
            }
        }

        for(auto x : squareC) roundC.insert(x);
        for(auto x : squareO) roundO.insert(x);

        ans += roundC.size()/2;
        ans += roundO.size()/2;
        if(roundC.size() % 2) {
            if(*roundO.begin() < *prev(roundC.end())) ++ans;
            else ans += 2;
        }
        cout << ans << "\n";
        
    }
}