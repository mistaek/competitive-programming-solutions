/*
2191C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<int> a(n), sorted; 
        for(int i = 0; i < n; ++i){
            char c; cin >> c; 
            a[i] = c - '0';
        }
        sorted = a;

        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for(int i = 0; i < n; ++i){
           if(a[i] != sorted[i]) ++ans;
        }

        if(ans == 0) cout << "Bob\n"; 
        else {
            cout << "Alice\n" << ans << "\n";
            bool space = false;
            for(int i = 0; i < n; ++i){
                if(sorted[i] != a[i]) {
                    if(space) cout << " ";
                    cout << i+1;
                    space = true;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}