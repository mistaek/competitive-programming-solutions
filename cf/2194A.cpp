/*
2194A
*/

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, w; cin >> n >> w;
        cout << n - (n/w) << "\n";
    }

    return 0;
}