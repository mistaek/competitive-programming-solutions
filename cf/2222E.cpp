/*
2222E
*/

#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << 0 << endl;
        cout << "I 0" << endl;
        int sz; cin >> sz;
        long long k = 0, c = 0;
        if (sz == 1) {
            k = 1;
            cout << "I " << (1LL << n) - 1 << endl;
            int resp; cin >> resp;
        }

        long long lo = 1, hi = (1LL << n)-1;
        while(lo < hi) {
            long long m = (lo + hi + 1)/2;
            cout << "Q " << m << endl;
            int resp; cin >> resp;
            if(resp) {
                lo = m;
            }
            else {
                hi = m-1;
            }
        }
        c = lo;
        if (k == 0) {
            // need to differentiate between 2 and 3
            long long bit = 0;
            for(int i = 0; i < n; ++i) {
                if(c & (1LL << i)) {
                    bit = (1LL << i);
                    break;
                }
            } 
            if (bit != c) {
                cout << "I " << bit << endl;
                int resp; cin >> resp;
                if(resp == 2) k = 2;
                else k = 3;
            }
            else {
                // bit is equal to c, need a different trick
                if (bit == 1) bit = 3;
                else bit = c+1;
                cout << "I " << bit << endl;
                int resp; cin >> resp;
                cout << "Q " << 3 << endl;
                cin >> resp;
                if (resp == 1 + ((c >= 3) ? 1 : 0)) k = 2;
                else k = 3;
            }
        }
        
        cout << "A " << k << " " << c << endl;
    }
    return 0;
}