/*
2220A
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main() {
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>()); 
        bool pos = true;
        for(int i = 1; i < n; ++i) {
            if (a[i] == a[i-1]) pos = false;
        }

        if(pos) {
            for(int i = 0; i < n; ++i) {
                if(i) cout << " ";
                cout << a[i];
            }
            cout << "\n";
        }
        else cout << "-1\n";
    }    
    return 0;
}