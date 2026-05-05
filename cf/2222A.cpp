/*
2222A
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool possible = false;
        for(int i = 0; i < n; ++i){ 
            cin >> a[i];
            a[i] = 100/a[i];
            if(a[i] == 1) possible = true;
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}