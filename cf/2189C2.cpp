/*
2189C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        bool possible = false;
        vector<int> ans(n+1, 0), pos(n+1, 0);
        ans[n] = 1; pos[1] = n;
        for(int i = 2; i < n; ++i){
            ans[i] = i ^1;
            pos[ans[i]] = i;
        }
        for(int i = 1; i<=n; ++i){
            if(!pos[i]){
                ans[1] = i;
                pos[i] = 1;
                break;
            }
        }

        if((ans[1]^1) > n) {
            for(int i = 2; i < n; ++i){ 
                if((ans[i]^1) > n) continue;
                if((ans[1] ^ i) > n) continue;
                if(pos[ans[1] ^ i] > i) {
                    possible = true;
                    swap(ans[1], ans[i]);
                    break;
                }
            }
        }
        else {
            possible = true;
        }
        if(!possible) {
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i <= n; ++i){
            if(i > 1) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}