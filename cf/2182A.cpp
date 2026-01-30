/*
2182A
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool found2026 = (s.find("2026") != string::npos);
        bool found2025 = (s.find("2025") != string::npos);

        if(found2026) cout << "0\n";
        else if (found2025) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}