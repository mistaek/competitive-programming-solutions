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
        long long n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        } 
        long long ans = 0;
        for(long long i = 0; i < n; ++i) {
            if(a[i] > 447) {
                // check all
                for(long long j = 1; i + j*a[i] < n; ++j) {
                    if(a[i+j*a[i]] == j) ++ans;
                }
                for(long long j = 1; i - j*a[i] >= 0; ++j) {
                    if(a[i - j*a[i]] == j) ++ans;
                }
            }
            else {
                // check fwd
                for(long long j = 1; i + j*a[i] < n && j <= 447; ++j){ 
                    if(a[i + j*a[i]] == j) ++ans;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}