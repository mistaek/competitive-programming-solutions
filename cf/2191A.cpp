/*
2191A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());

        bool pos = true;
        for(int i= 1; i < n; ++i){
            if(a[i].second % 2 == a[i-1].second % 2) pos = false;
        }

        cout << (pos ? "YES\n" : "NO\n");
    }    
    
    return 0;
}