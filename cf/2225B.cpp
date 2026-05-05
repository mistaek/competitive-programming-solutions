/*
2225B
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int infractions = 0;
        for(int i = 0; i < (int)s.length()-1; ++i){
            if(s[i] == s[i+1]) ++infractions;
        }

        if(infractions > 2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}