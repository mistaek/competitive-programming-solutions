/*
2197A
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
        long long x; cin >> x;
        long long ans = 0;
        for(long long i = x; i <= x + 90; ++i) {
            long long di = 0, copy = i;
            while(copy) {
                di += copy % 10;
                copy /=10;
            }
            if(i - di == x) ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}