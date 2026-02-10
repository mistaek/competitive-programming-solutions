/*
2178A
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--){
        string s; cin >> s;
        int cnt = 0;
        for(char c : s) {
            if(c == 'Y') ++cnt;
        }

        if(cnt >= 2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}