/*
2197C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long p, q; cin >> p >> q;
        if(3*p < 2 * q || q <= p) {
            cout << "Alice\n";
        }
        else {
            long long delta = q - p;
            if(q >= 3*delta) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }
    return 0;
}