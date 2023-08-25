/*
1857F
AC
*/

#include <iostream>
#include <map>
#include <cmath>
using namespace std; 

int main(){
    int t; cin >> t; 

    while(t--){
        int n; cin >> n; 
        map<long long, long long> cnt; 
        for(int i = 0; i < n; i++){
            long long v; cin >> v; 
            cnt[v]++; 
        }
        int q; cin >> q;
        for(int i =0; i < q; i++){
            if(i) cout << " "; 
            long long x, y; cin >> x>>y;
            long long det = (x*x) - 4LL*y;
            if(det < 0) {
                cout << 0; 
                continue;
            }
            long long rt = sqrt(det); 
            if(rt * rt != det){
                cout << 0;
                continue;
            }
            long long a = x + rt;
            if(a % 2){
                cout << 0; continue; 
            }
            a /= 2; 
            if(y % a){
                cout << 0; 
                continue; 
            }
            if(a*a == y){
                cout << (cnt[a] * (cnt[a] - 1LL))/2LL;
            }
            else cout << cnt[a] * cnt[y/a];

        }
        cout << "\n";
    }
    return 0;   
}