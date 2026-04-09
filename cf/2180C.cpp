/*
2180C
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        if(k % 2) {
            for(int i = 0; i < k; ++i) {
                if(i) cout << " ";
                cout << n;
            }
            cout << "\n";
            continue;
        }


        vector<int> bits; 
        for(int j = 30; j >= 0; --j) {
            if(n & (1 << j)) bits.push_back(j);
        }

        int p = bits.size();
        int once = 0;
        if(p %2) {
            --p;
            once = (1<<bits[p]);
        }
        if(k < p) {
            for(int i = k; i < p; ++i){
                once += (1 << bits[i]);
            }
        }

        for(int i = 0; i < min(p, k); i += 2){
            int big = 0, small = 0;
            for(int j = 30; j > bits[i]; --j) if(n & (1 <<j)) big |= (1<<j);
            small = big;
            small += (1<<(bits[i+1] +1)) -1;
            big += (1<<bits[i]) + (1 << (bits[i+1])) - 1;
            if(i == 0) big -= once;
            if(i) cout << " ";
            cout << small << " " << big;
        }

        if(p == 0) {
            cout << "0";
            for(int i = 1; i < k; ++i) {
                cout << " " << n; 
            }
        }
        else {
            for(int i = p; i < k; ++i) cout << " " << n;
        }
        cout << "\n";
        
        
    }
    return 0;
}