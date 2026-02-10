/*
2178B
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--){
        string s; cin >> s;
        int cnt = 0, n = s.length();
        if(s[0] == 'u'){
            ++cnt; s[0] = 's';
        }
        if(s[n-1] == 'u'){
            ++cnt; s[n-1] = 's';
        }
        for(int i = 1; i < n-1; ++i) {
            if(s[i] == 'u' && s[i-1] == 'u') {
                ++cnt;
                s[i] = 's';
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}