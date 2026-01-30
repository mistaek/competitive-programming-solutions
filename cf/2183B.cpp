/*
2183B
*/

#include <iostream>
#include <vector>

using namespace std; 


int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> cnt(2e5 + 1, 0);
        for(int i = 0; i < n; ++i){
            int a; cin >> a;
            cnt[a]++;
        }

        int ans =0;
        for(; ans < k-1; ++ans){
            if(!cnt[ans]) break;
        }

        cout << ans << "\n";
    }
    return 0;
}