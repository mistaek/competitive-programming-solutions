/*
2176A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int ans = 0, curmax = 0;
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            if(a < curmax) ++ans;
            curmax = max(curmax, a);
        }
        cout << ans << "\n";
    }
    return 0;
}