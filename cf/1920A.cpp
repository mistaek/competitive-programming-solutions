/*
1920A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> neq; 
        int mn = 0, mx = 1e9; 
        for(int i = 0; i < n; i++){
            int a, x; cin >> a >> x; 
            if(a == 3) neq.push_back(x); //guarantee no two same, so all neqs should be distinct
            else if(a == 1) mn = max(mn, x);
            else if(a == 2) mx = min(mx, x);
        }

        if(mn > mx){
            cout << 0 << "\n";
        }
        else{
            int ans = mx - mn + 1;
            for(int x : neq){
                if(x >= mn && x <= mx){
                    ans--;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}