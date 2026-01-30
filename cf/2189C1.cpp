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
        for(int i = 0; i < 30; ++i){

        }
        vector<int> ans(n+1, 0), present(n+1, 0);
        ans[n] = 1; present[1] = 1;
        for(int i = 2; i < n; ++i){
            ans[i] = i ^1;
            present[ans[i]] = 1;
        }
        for(int i = 1; i<=n; ++i){
            if(!present[i]){
                ans[1] = i;
                break;
            }
        }
        for(int i = 1; i <= n; ++i){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}