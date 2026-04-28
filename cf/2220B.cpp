/*
2220B
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int same = 1;
        bool pos = true;
        for(int i = 1; i < n; ++i) {
            if(a[i] == a[i-1]) ++same;
            else same = 1;
            if(same == m) pos = false; 
        }

        if(!pos) cout << "NO\n";
        else cout << "YES\n";
    }    
    return 0;
}