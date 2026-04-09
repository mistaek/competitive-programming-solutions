/*
2211A
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n); 
        for(int i = 0; i < n; ++i) cin >> a[i];

        for(int i = 0; i < n; ++i) {
            cout << " ";
            if(n <= 2) cout << n;
            else cout << 2;
        }
        cout << "\n";
    }
    return 0; 
}