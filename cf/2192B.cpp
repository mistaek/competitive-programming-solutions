/*
2192B
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
        vector<int> ones, zeros;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                zeros.push_back(i+1);
            }
            else ones.push_back(i+1);
        }
        if(ones.size() == 0) cout << "0\n";
        else if(ones.size() % 2 && zeros.size() % 2 == 0) cout << "-1\n";
        else if(ones.size() % 2 || (zeros.size() <= ones.size() && zeros.size() % 2)) {
            cout << zeros.size() << "\n";
            for(int i = 0; i < (int) zeros.size(); ++i) {
                if(i) cout << " ";
                cout << zeros[i];
            }
            cout << "\n";
        }
        else {
            cout << ones.size() << "\n";
            for(int i = 0; i < (int) ones.size(); ++i) {
                if(i) cout << " ";
                cout << ones[i];
            }
            cout << "\n";
        }
    }
    return 0;
}