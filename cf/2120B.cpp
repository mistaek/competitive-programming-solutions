/*
2120A
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n, s; cin >> n >> s; 
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int dx, dy, x, y; cin >> dx >> dy >> x >> y; 
            if((s + dx * x) % s == ( s + dy * y) % s) ++ans; 
        }
        cout << ans << "\n";
    }
    return 0;
}