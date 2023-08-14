/*
1846E2
AC
*/

#include <iostream>
#include <set>
#include <climits>
#include <cmath>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<long long> pos; 
    for(long long i = 2; i <= 1000000; i++){
        long long base = 1 + i + (i * i);
        pos.insert(base); 
        long long pow = i * i;
        //cout << base << "\n";
        while(pow > 0 && (LLONG_MAX / pow) >= i){
            pow *= i; 
            base += pow; 
            pos.insert(base);
            //cout << base << "\n";
 
        }
    }
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        if(pos.count(n)) cout << "yes\n"; 
        else {
            long long dt = 4 * n - 3; 
            long long rt = sqrt(dt); 
            if(rt > 5LL && rt * rt == dt) cout << "yes\n"; 
            else cout << "no\n";
        }
    }
    return 0;
}