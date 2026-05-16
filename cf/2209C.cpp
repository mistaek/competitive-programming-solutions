/*
2209C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool ans = false;
        for (int i = 1; i < n; ++i) {
            cout << "? " << i << " " << i+n << endl;
            int resp;
            cin >> resp;
            if(resp){ 
                ans = true;
                cout << "! " << i << endl;
                break;
            }
        }

        if(!ans) {
            int resp;
            cout << "? " << 1 << " " << n << endl;
            cin >> resp;
            if(resp) {
                cout << "! " << 1 << endl;
                continue;
            }
            cout << "? " << n << " " << n+1 << endl;
            cin >> resp;
            if (resp) {
                cout << "! " << n << endl;
                continue;
            }
            else cout << "! " << 2*n << endl;
        }
    }
    return 0;
}