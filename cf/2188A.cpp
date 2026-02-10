/*
2188A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> ans(n, 0);
        int val = 1;
        for(int i = n-1; i >= 0; i-=2) {
            ans[i] = val++;
        }
        val = n;
        for(int i = n-2; i >= 0; i-=2) {
            ans[i] = val--;
        }

        for(int i = 0; i < n; ++i){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}