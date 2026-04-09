/*
2217B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

int main(){
    int t; cin >> t;
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        if (gcd(n, a) > 1 || gcd(m, b) > 1 || gcd(n, m) > 2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}