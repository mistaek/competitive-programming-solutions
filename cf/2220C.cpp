/*
2220B
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--) {
        long long p, q; cin >> p >> q;
        bool pos = false;
        for(long long n = 1; n*n <= p + 2*q; ++n) {
            if ((p + 2*q - n) % (2*n+1)) continue;
            long long m = (p+2*q-n)/(2*n+1);
            
            if (n > m) break;
            //cout << "Testing " << n << " " << m << "\n";
            if (p < m-n) {
                //cout << "Not enough straight segments\n";
                continue; 
            }
            else {
                pos = true;
                cout << n << " " << m << "\n";
                break;
            }
        }
        if(!pos) cout << "-1\n";
    }    
    return 0;
}